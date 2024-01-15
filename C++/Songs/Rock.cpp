#include "Rock.h"
using namespace std;

Rock::Rock() {
    has_distorted_guitar = 0;
    has_clean_guitar = 0;
    has_vocal = 0;
    has_growls = 0;
    cout << "Rock song object created" << endl;
}

Rock::~Rock() {
    cout << "Rock song object destroyed" << endl;
}

bool Rock::get_has_distorted_guitar() {
    return has_distorted_guitar;
}
bool Rock::get_has_clean_guitar() {
    return has_clean_guitar;
}
bool Rock::get_has_vocal() {
    return has_vocal;
}
bool Rock::get_has_growls() {
    return has_growls;
}

void Rock::set_has_distorted_guitar(bool b) {
    has_distorted_guitar = b;
}
void Rock::set_has_clean_guitar(bool b) {
    has_clean_guitar = b;
}
void Rock::set_has_vocal(bool b) {
    has_vocal = b;
}
void Rock::set_has_growls(bool b) {
    has_growls = b;
}

double Rock::calc_typicalness() {
    // cout << "There are 3 typicalness points you can get for the genre of rock." << endl;
    // cout << "The more points you get, the more 'average' and genre-fitting the song is." << endl;
    double points = (has_distorted_guitar || has_clean_guitar) + has_vocal + has_growls;
    return (points * 100) / 3;
}

void Rock::Print() {
    Song::Print();
    cout << " Has distorted guitars: " << has_distorted_guitar << endl <<
        " Has clean (acoustic / electric) guitars: " << has_clean_guitar << endl <<
        " Has vocal: " << has_vocal << endl <<
        " Has growls: " << has_growls << endl <<
		round(calc_typicalness()) << "% typical for the genre Rock" << endl;
}

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
		end_result += genres[i].name + "\n";
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
    end_result += "</Rock>\n";

	return end_result;
}

void Rock::Fill() {
    Song::Fill();

    string user_input;
    int user_int;
    bool user_bool;

    cout << "Does the song have distorted electric guitars? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_has_distorted_guitar(user_bool);

    cout << "Does the song have clean guitars? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_has_clean_guitar(user_bool);

    cout << "Does the song have vocal? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_has_vocal(user_bool);

    cout << "Does the song have growls? (1 - yes, 0 - no) ";
	getline(cin, user_input);
    cast_to_bool(user_input, user_bool);
	set_has_growls(user_bool);
}

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
    set_has_distorted_guitar(user_bool);
    cast_to_bool(tokens[i++], user_bool);
    set_has_clean_guitar(user_bool);
    cast_to_bool(tokens[i++], user_bool);
    set_has_vocal(user_bool);
    cast_to_bool(tokens[i++], user_bool);
    set_has_growls(user_bool);
}

void Rock::edit_menu() {
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
			<< "14 - Has distorted guitars" << endl
			<< "15 - Has clean guitars" << endl
			<< "16 - Has vocals" << endl
			<< "17 - Has growls" << endl
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
			set_has_distorted_guitar(user_bool);
			break;
		case 15:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_has_clean_guitar(user_bool);
			break;
		case 16:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_has_vocal(user_bool);
			break;
		case 17:
			getline(cin, user_input);
			cast_to_bool(user_input, user_bool);
			set_has_growls(user_bool);
			break;
		case 0:
			return;
		}
	}
}