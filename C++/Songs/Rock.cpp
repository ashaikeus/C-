#include "Rock.h"

Rock::Rock() {
    has_distorted_guitar = 0;
    has_clean_guitar = 0;
    has_vocal = 0;
    has_growls = 0;
    cout << "Rock song object created" << endl;
};

Rock::~Rock() {
    cout << "Rock song object destroyed" << endl;
};

bool Rock::get_has_distorted_guitar() {
    return has_distorted_guitar;
};
bool Rock::get_has_clean_guitar() {
    return has_clean_guitar;
};
bool Rock::get_has_vocal() {
    return has_vocal;
};
bool Rock::get_has_growls() {
    return has_growls;
};

void Rock::set_has_distorted_guitar(bool b) {
    has_distorted_guitar = b;
};
void Rock::set_has_clean_guitar(bool b) {
    has_clean_guitar = b;
};
void Rock::set_has_vocal(bool b) {
    has_vocal = b;
};
void Rock::set_has_growls(bool b) {
    has_growls = b;
};

int Rock::calc_typicalness() {
    cout << "There are 3 typicalness point you can get for the genre of rock." << endl;
    cout << "The more points you get, the more 'average' and genre-fitting the song is." << endl;
    int points = (has_distorted_guitar || has_clean_guitar) + has_vocals + has_growls;
    return points;
};

void Rock::Print() {
    Song::Print();
    cout << " Has distorted guitars: " << has_distorted_guitar << endl <<
        " Has clean (acoustic / electric) guitars: " << has_clean_guitar << endl <<
        " Has vocal: " << has_vocal << endl <<
        " Has growls: " << has_growls << endl;
};

string Rock::to_String() {
    string end_result = "";
    end_result += "<Rock>\n";
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

    end_result += bts(has_distorted_guitar) + "\n" + bts(has_clean_guitar) + "\n"
                + bts(has_vocal) + "\n" + bts(has_growls) + "\n";
    end_result += "</Rock>";
};

void Rock::Fill() {
    Song::Fill();

    string user_input;
    int user_int;
    bool user_bool;

    cout << "Does the song have distorted electric guitars? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_has_distorted_guitar(bts(user_input));

    cout << "Does the song have clean guitars? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_has_clean_guitar(bts(user_input));

    cout << "Does the song have vocal? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_has_vocal(bts(user_input));

    cout << "Does the song have growls? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	set_has_growls(bts(user_input));
};

void Rock::Load(vector<string> tokens) {
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
    set_has_distorted_guitar(user_bool);
    set_has_clean_guitar(user_bool);
    set_has_vocal(user_bool);
    set_has_growls(user_bool);
};