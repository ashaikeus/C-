#include "Book.h"
using namespace std;

Book::Book() {
    name = "Story name";
    author = "Folklore";
	cout << "Book object created" << endl;
}

Book::~Book() {
	cout << "Book object destroyed" << endl;
}

string Book::get_name() { return name; }
string Book::get_author() { return author; }
int Book::get_pages() { return pages; }

void Book::set_name(string new_) { name = new_; }
void Book::set_author(string new_) { author = new_; }
void Book::set_pages(int new_) { pages = new_; }

Audiobook::Audiobook() {
	cout << "Audiobook object created" << endl;
}

Audiobook::~Audiobook() {
    voice_actors.clear();
	cout << "Audiobook object destroyed" << endl;
}

vector<string> Audiobook::get_voice_actors() { return voice_actors; }
int Audiobook::get_length() { return pages * 2.5 * 60; }
// ^ из расчёта, что вслух страницу средней книги читают две с половиной минуты

void Audiobook::set_voice_actors(vector<string> new_) { featuring = new_; }

void Audiobook::set_pages(int new_) {
    if (new_ == -1) {
		new_ = 0;
    } else if (new_ < 0) {
		cout << "WRONG" << endl;
		return;
	}
    pages = new_;
}

void Audiobook::edit_menu() {
	string user_input;
	int int_case, user_int;
	float user_float;
	bool user_bool;

	while (1) {
		cout << "Edit options" << endl
			<< "1 - Name" << endl
			<< "2 - Author" << endl
			<< "3 - Page count" << endl
			<< "4 - Voice actors" << endl
			<< "0 - Go back" << endl << "> ";
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			getline(cin, user_input);
			Book::set_name(user_input);
			break;
        case 2:
            getline(cin, user_input);
			set_author(user_input);
			break;
        case 3:
            getline(cin, user_input);
            cast_to_number(user_input, user_int);
			set_pages(user_int);
			break;
        case 4:
            edit_voice_actors();
			break;
        case 0:
            return;
        }
    }
}

void Audiobook::edit_voice_actors() {
	string user_input;
	cout << "Add voice actors (0 to exit):" << endl;
	while (1) {
		getline(cin, user_input);
		if (user_input == "0")
			break;
		if (user_input != "") {
            voice_actors.push_back(user_input);
        } else {
            cout << "Empty voice actor name" << endl;
        }
	}
}

void Audiobook::Fill() {
    string user_input;
    int user_int;
    bool user_bool;

    cout << "Audiobook name: ";
	getline(cin, user_input);
	Book::set_name(user_input);

    cout << "Author name: ";
	getline(cin, user_input);
	set_author(user_input);

    cout << "Original book page count: ";
	getline(cin, user_input);
    cast_to_number(user_input, user_int);
	set_pages(user_int);

    cout << "Language: ";
	getline(cin, user_input);
	set_language(user_input);

    edit_voice_actors();
}

void Audiobook::Print() {
    cout << "Name: " << "\"" << Book::get_name() << "\"" << endl <<
        "Author: " << get_author() << endl <<
        "Pages count: " << get_pages() << endl <<
        "Length: " << Audiobook::get_length() / 3600 << ":" <<
        two_digitize(Audiobook::get_length() / 60 - (Audiobook::get_length() / 3600) * 60) << ":" <<
        two_digitize(Audiobook::get_length() % 60) << endl <<
        "Language: " << get_language() << endl;
    if (not voice_actors.empty()) {
        cout << "Voice actors: " << endl;
        for (int i = 0; i < voice_actors.size(); i++) {
            cout << voice_actors[i];
            if (i + 1 != voice_actors.size()) cout << ", ";
            else cout << endl;
        }
    }
}

string Audiobook::to_String() {
    string output;
    output = "";
    output += "<Audiobook>\n";
    output += Book::get_name() + "\n";
    output += Book::get_author() + "\n";
    output += to_string(get_pages()) + "\n";
    output += language + "\n";
    output += "<Voice actors>\n";
	for (int i = 0; i < get_voice_actors().size(); i++) {
		output += get_voice_actors()[i] + "\n";
	}
    output += "</Voice actors>\n";
    output += "</Audiobook>\n";
    return output;
}

void Audiobook::Load(vector<string> tokens) {
    bool user_bool;
    int user_int;
    int i = 0;

    Book::set_name(tokens[i++]);
    set_author(tokens[i++]);
    cast_to_number(tokens[i++], user_int);
	set_pages(user_int);
    set_language(tokens[i++]);

    if (tokens[i] != "<Voice actors>") {
		cout << "! Invalid data: voice actors not found" << endl;
		return;
	}
	i++;
	while (tokens[i] != "</Voice actors>") {
		voice_actors.push_back(tokens[i++]);
	}
	i++;
}