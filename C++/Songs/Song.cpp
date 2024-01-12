#include "Song.h"

Song::Song() {
    name = "Untitled";
    artist = "Unknown";
    album = "Unknown";
    label = "Unknown";
    language = "None";
    year = -1;
    length = 0;
    bool is_explicit = 0;
	cout << "Song object created" << endl;
};

Song::~Song() {
    genres.clear();
    featuring.clear();
    lyricists.clear();
    nominations.clear();
    used_in.clear();
	cout << "Song object destroyed" << endl;
};

string Song::get_name() {
    return name;
};
string Song::get_artist() {
    return artist;
};
string Song::get_album() {
    return album;
};
string Song::get_label() {
    return label;
};
string Song::get_language() {
    return language;
};
int Song::get_year() {
    return year;
};
int Song::get_length() {
    return length;
};
bool Song::get_is_explicit() {
    return is_explicit;
};
vector<string> Song::get_genres() {
    return genres;
};
vector<string> Song::get_featuring() {
    return featuring;
};
vector<string> Song::get_lyricists() {
    return lyricists;
};
vector<string> Song::get_nominations() {
    return nominations;
};
vector<string> Song::get_used_in() {
    return used_in;
};

void Song::set_name(string newname) {
    name = newname;
};
void Song::set_artist(string new_) {
    artist = new_;
};
void Song::set_album(string new_) {
    album = new_;
};
void Song::set_label(string new_) {
    label = new_;
};
void Song::set_language(string new_language) {
    if new_language.length() == 0 {
        cout << "Language can't be empty" << endl;
        return;
    }
    language = new_language;
};

void Song::set_year(int new_) {
    year = new_;
};
void Song::set_length(int new_) {
    length = new_;
};
void Song::set_is_explicit(bool new_) {
    is_explicit = new_;
};
void Song::set_genres(vector<string> new_) {
    genres = new_;
};
void Song::set_featuring(vector<string> new_) {
    featuring = new_;
};
void Song::set_lyricists(vector<string> new_) {
    lyricists = new_;
};
void Song::set_nominations(vector<string> new_) {
    nominations = new_;
};
void Song::set_used_in(vector<string> new_) {
    used_in = new_;
};

void Song::add_genre(string g) {
    if (g == "") {
		cout << "! Empty name of the genre" << endl;
		return;
	}
	genres.push_back(g);
};
void Song::add_featuring(string g) {
    if (g == "") {
		cout << "! Empty name of the featuring artist" << endl;
		return;
	}
	featuring.push_back(g);
};
void Song::add_lyricists(string g) {
    if (g == "") {
		cout << "! Empty name of the lyricist" << endl;
		return;
	}
	lyricists.push_back(g);
};
void Song::add_nominations(string g) {
    if (g == "") {
		cout << "! Empty name of the nomination" << endl;
		return;
	}
	nominations.push_back(g);
};
void Song::add_used_in(string g) {
    if (g == "") {
		cout << "! Empty name of the media in which the song was used" << endl;
		return;
	}
	used_in.push_back(g);
};

int Song::calc_typicalness() {
	cout << "Can't calculate the \"typicalness\" of this song: it has no subgenre information" << endl;
	return -1;
};

void Song::Print() {
    cout << " " << artist " - " << name
        << " (" << length / 60 << ":" << length % 60 << endl
        << "(" << album << ", " << year << ")" << endl 
        << "Label: " << label << endl
		<< "Language: " << language << endl;
    if (is_explicit) cout << "Explicit" << endl;
    if (genres.empty()) {
        cout << "No genre" << endl;
    } else {
        cout << "Genres: ";
        for (int i = 0; i < genres.size(); i++) {
            cout << genres[i];
            if (i + 1 != genres.size()) cout << ", ";
            else cout << endl;
        }
    }
    if (not featuring.empty()) {
        cout << "Featuring " << endl;
        for (int i = 0; i < featuring.size(); i++) {
            cout << featuring[i];
            if (i + 1 != featuring.size()) cout << ", ";
            else cout << endl;
        }
    }
    if (not lyricists.empty()) {
        cout << "Lyricists are " << endl;
        for (int i = 0; i < lyricists.size(); i++) {
            cout << lyricists[i];
            if (i + 1 != lyricists.size()) cout << ", ";
            else cout << endl;
        }
    }
    if (not nominations.empty()) {
        cout << "Nominations for this song: " << endl;
        for (int i = 0; i < nominations.size(); i++) {
            cout << nominations[i];
            if (i + 1 != nominations.size()) cout << ", ";
            else cout << endl;
        }
    }
    if (not used_in.empty()) {
        cout << "Song used in " << endl;
        for (int i = 0; i < used_in.size(); i++) {
            cout << used_in[i];
            if (i + 1 != used_in.size()) cout << ", ";
            else cout << endl;
        }
    }
};

void Song::to_String() {
    string end_result = "";
    end_result += "<Song>\n";
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
    end_result += "</Song>";
};

void Song::Fill() {
    string user_input;
    int user_int;
    bool user_bool;

    cout << "Name of the artist: ";
	getline(cin, user_input);
	set_artist(user_input);

    cout << "Name of the song: ";
	getline(cin, user_input);
	set_name(user_input);

    cout << "Name of the album: ";
	getline(cin, user_input);
	set_album(user_input);

    cout << "Name of the label: ";
	getline(cin, user_input);
	set_label(user_input);

    cout << "Language used in the song: ";
	getline(cin, user_input);
	set_language(user_input);

	cout << "Length of the song (in seconds): ";
	getline(cin, user_input);
	cast_to_number(user_input, user_int);
	set_length(user_int);

	cout << "Release year: ";
	getline(cin, user_input);
	cast_to_number(user_input, user_int);
	set_year(user_int);

	cout << "Does this song contain swear words or mature themes? (1 - yes, 0 - no) ";
	getline(cin, user_input);
	cast_to_bool(user_input, user_bool);
	set_is_explicit(user_bool);

	cout << "Genres (0 to stop): ";
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		add_genre(user_input);
	}
	cout << "Featuring (0 to stop): ";
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		add_featuring(user_input);
	}
	cout << "Lyricists (0 to stop): ";
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		add_lyricists(user_input);
	}
	cout << "Nominations (0 to stop): ";
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		add_nominations(user_input);
	}
	cout << "Used in (0 to stop): ";
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		add_used_in(user_input);
	}
};

void Song::Load(vector<string> tokens) {
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
};