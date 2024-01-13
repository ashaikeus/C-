#include "Hiphop.h"
using namespace std;

Hiphop::Hiphop() {
    is_by_black = 0;
    is_by_woman = 0;
    is_very_fast = 0;
    swear_words = 0;
    cout << "Hiphop song object created" << endl;
}

Hiphop::~Hiphop() {
    cout << "Hiphop song object destroyed" << endl;
}

bool Hiphop::get_is_by_black() {
    return is_by_black;
}
bool Hiphop::get_is_by_woman() {
    return is_by_woman;
}
bool Hiphop::get_is_very_fast() {
    return is_very_fast;
}
int Hiphop::get_swear_words() {
    return swear_words;
}

void Hiphop::set_is_by_black(bool is_black) {
    is_by_black = is_black;
}
void Hiphop::set_is_by_woman(bool is_woman) {
    is_by_woman = is_woman;
}
void Hiphop::set_is_very_fast(bool is_fast) {
    is_very_fast = is_fast;
}
void Hiphop::set_swear_words(int swears) {
    if (swears < 0) {
        cout << "you're insane, how can you swear " << swears << " times in the song? impossible" << endl;
        return;
    }
    if (swears > 0) {
        is_explicit = true;
    }
    swear_words = swears;
}

double Hiphop::calc_typicalness() {
    // cout << "There are 4 typicalness points you can get for the genre of hiphop." << endl;
    // cout << "The more points you get, the more 'average' and genre-fitting the song is." << endl;
    double points = is_by_black + not(is_by_woman) + is_very_fast + is_explicit;
    return points / 4;
}

void Hiphop::Print() {
    Song::Print();
    cout << " Is made by a black person: " << is_by_black << endl <<
        " Is made by a woman: " << is_by_woman << endl <<
        " Is very fast: " << is_very_fast << endl <<
        " Contains " << swear_words << " swear words" << endl <<
		calc_typicalness() << "% typical for the genre Hiphop" << endl;
}

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
    end_result += "</Hiphop>\n";

    return end_result;
}

void Hiphop::Fill() {
    Song::Fill();

    string user_input;
    int user_int;
    bool user_bool;

    cout << "Is the song by a black artist? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_is_by_black(user_bool);

    cout << "Is the song by a woman? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_is_by_woman(user_bool);

    cout << "Does this song contain very fast rap parts? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_is_very_fast(user_bool);

    cout << "How many swear words does this song contain? ";
	getline(cin, user_input);
	cast_to_number(user_input, user_int);
	set_swear_words(user_int);
}

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
		add_lyricist(tokens[i++]);
	}
	i++;

    if (tokens[i] != "<Nominations>") {
		cout << "! Invalid data: nominations not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Nominations>") {
		add_nomination(tokens[i++]);
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
}

void Hiphop::edit_menu() {
	string user_input;
	int int_case, user_int;
	float user_float;
	bool user_bool;

	while (1) {
		cout << "Edit options" << endl
			<< "1 - Name" << endl
			<< "2 - Artist" << endl
			<< "3 - Album" << endl
			<< "4 - Label" << endl
			<< "5 - Language" << endl
			<< "6 - Year" << endl
			<< "7 - Length" << endl
			<< "8 - Explicit or family friendly" << endl
			<< "9 - Genres" << endl
			<< "10 - Featuring" << endl
			<< "11 - Lyricists" << endl
			<< "12 - Nominations" << endl
			<< "13 - Used in" << endl
			<< "14 - Is by a black person" << endl
			<< "15 - Is by a woman" << endl
			<< "16 - Contains very fast rap parts" << endl
			<< "17 - Swear words count" << endl
			<< "0 - Exit" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			getline(cin, user_input);
			set_name(user_input);
			break;
		case 2:
			getline(cin, user_input);
			set_artist(user_input);
			break;
		case 3:
			getline(cin, user_input);
			set_album(user_input);
			break;
		case 4:
			getline(cin, user_input);
			set_label(user_input);
			break;
		case 5:
			getline(cin, user_input);
			set_language(user_input);
			break;
		case 6:
			getline(cin, user_input);
			cast_to_number(user_input, user_int);
			set_year(user_int);
			break;
		case 7:
			getline(cin, user_input);
			cast_to_number(user_input, user_int);
			set_length(user_int);
			break;
		case 8:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_is_explicit(user_bool);
			break;
		case 9:
			edit_vectors('g');
			break;
		case 10:
			edit_vectors('f');
			break;
		case 11:
			edit_vectors('l');
			break;
		case 12:
			edit_vectors('n');
			break;
		case 13:
			edit_vectors('u');
			break;
		case 14:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_is_by_black(user_bool);
			break;
		case 15:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_is_by_woman(user_bool);
			break;
		case 16:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_is_very_fast(user_bool);
			break;
		case 17:
			getline(cin, user_input);
			cast_to_number(user_input, user_int);
			set_swear_words(user_int);
			break;
		}
	}
}