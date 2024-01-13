#include "Hiphop.h"

Hiphop::Hiphop() {
    is_by_black = 0;
    is_by_woman = 0;
    is_very_fast = 0;
    swear_words = 0;
    cout << "Hiphop song object created" << endl;
};

Hiphop::~Hiphop() {
    cout << "Hiphop song object destroyed" << endl;
};

bool Hiphop::get_is_by_black() {
    return is_by_black;
};
bool Hiphop::get_is_by_woman() {
    return is_by_woman;
};
bool Hiphop::get_is_very_fast() {
    return is_very_fast;
};
int Hiphop::get_swear_words() {
    return swear_words;
};

void Hiphop::set_is_by_black(bool is_black) {
    is_by_black = is_black;
};
void Hiphop::set_is_by_woman(bool is_woman) {
    is_by_woman = is_woman;
};
void Hiphop::set_is_very_fast(bool is_fast) {
    is_very_fast = is_fast;
};
void Hiphop::set_swear_words(int swears) {
    if (swears < 0) {
        cout << "you're insane, how can you swear " << swears << " times in the song? impossible" << endl;
        return;
    }
    if (swears > 0) {
        is_explicit = true;
    }
    swear_words = swears;
};

int Hiphop::calc_typicalness() {
    cout << "There are 4 typicalness point you can get for the genre of hiphop." << endl;
    cout << "The more points you get, the more 'average' and genre-fitting the song is." << endl;
    int points = is_by_black + not(is_by_woman) + is_very_fast + is_explicit;
    return points;
};

void Hiphop::Print() {
    Song::Print();
    cout << " Is made by a black person: " << is_by_black << endl <<
        " Is made by a woman: " << is_by_woman << endl <<
        " Is very fast: " << is_very_fast << endl <<
        " Contains " << swear_words << " swear words" << endl;
};

string Hiphop::to_String() {
    string end_result = "";
    end_result += "<Hiphop>\n";
    end_result += name + "\n" +
                artist + "\n" +
                album + "\n" +
                label + "\n" +
                language + "\n";
    end_result += to_string(year) + "\n" + to_string(length) + "\n" + to_string(is_explicit) + "\n";
    end_result += "<Genres>\n";
	for (int i = 0; i < genres.size(); i++) {
		end_result += genres[i] + "\n";
	}
	end_result += "</Genres>\n";
    end_result += "<Featuring>\n";
	for (int i = 0; i < featuring.size(); i++) {
		end_result += featuring[i] + "\n";
	}
	end_result += "</Featuring>\n";
    end_result += "<Lyricists>\n";
	for (int i = 0; i < lyricists.size(); i++) {
		end_result += lyricists[i] + "\n";
	}
	end_result += "</Lyricists>\n";
    end_result += "<Nominations>\n";
	for (int i = 0; i < nominations.size(); i++) {
		end_result += nominations[i] + "\n";
	}
	end_result += "</Nominations>\n";
    end_result += "<Used in>\n";
	for (int i = 0; i < used_in.size(); i++) {
		end_result += used_in[i] + "\n";
	}
	end_result += "</Used in>\n";

    end_result += bts(is_by_black) + "\n" + bts(is_by_woman) + "\n" + bts(is_very_fast) + "\n";
    end_result += to_string(swear_words) + "\n";
    end_result += "</Hiphop>";
};

void Hiphop::Fill() {
    Song::Fill();

    string user_input;
    int user_int;
    bool user_bool;

    cout << "Is the song by a black artist? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_is_by_black(bts(user_input));

    cout << "Is the song by a woman? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_is_by_woman(bts(user_input));

    cout << "Does this song contain very fast rap parts? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_is_very_fast(bts(user_input));

    cout << "How many swear words does this song contain? ";
	getline(cin, user_input);
	cast_to_number(user_input, user_int);
	set_swear_words(user_int);
};

void Hiphop::Load(vector<string> tokens) {
    bool user_bool;
    int user_int;
    int i = 0;

    set_name(tokens[i++]);
    set_artist(tokens[i++]);
    set_album(tokens[i++]);
    set_label(tokens[i++]);
    set_language(tokens[i++]);
    cast_to_number(tokens[i++], user_int);
	set_year(user_int);
    cast_to_number(tokens[i++], user_int);
	set_length(user_int);
    cast_to_bool(tokens[i++], user_bool);
    set_is_explicit(user_bool);

    if (tokens[i] != "<Genres>") {
		cout << "! Invalid data: genres not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Genres>") {
		add_genre(tokens[i++]);
	}
	i++;

    if (tokens[i] != "<Featuring>") {
		cout << "! Invalid data: featuring artists not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Featuring>") {
		add_featuring(tokens[i++]);
	}
	i++;

    if (tokens[i] != "<Lyricists>") {
		cout << "! Invalid data: lyricists not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Lyricists>") {
		add_lyricists(tokens[i++]);
	}
	i++;

    if (tokens[i] != "<Nominations>") {
		cout << "! Invalid data: nominations not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Nominations>") {
		add_nominations(tokens[i++]);
	}
	i++;

    if (tokens[i] != "<Used in>") {
		cout << "! Invalid data: used in not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Used in>") {
		add_used_in(tokens[i++]);
	}
	i++;

    cast_to_bool(tokens[i++], user_bool);
    set_is_by_black(user_bool);
    cast_to_bool(tokens[i++], user_bool);
    set_is_by_woman(user_bool);
    cast_to_bool(tokens[i++], user_bool);
    set_is_very_fast(user_bool);
    cast_to_number(tokens[i++], user_int);
	set_swear_words(user_int);
};