#include "Menu.h"

Menu::Menu() {
    load_songs();
}

Menu::~Menu() {
    cout << "Exit";
}

void Menu::Print() {
	cout << "List of songs: " << endl;
	for (int i = 0; i < Songs.size(); i++) {
		cout << i + 1 << ". ";
		Songs[i]->Print();
		cout << endl;
	}
}

void Menu::add_song() {
	Song* new_song = new Song();
	new_song->Fill();
	Songs.push_back(new_song);
}

void Menu::add_hiphop() {
	Hiphop* new_song = new Hiphop();
	new_song->Fill();
	Songs.push_back(new_song);
}

void Menu::add_rock() {
	Rock* new_song = new Rock();
	new_song->Fill();
	Songs.push_back(new_song);
}

void Menu::menu_add() {
    string user_input;
	int int_case = -1;
	while (1) {
		cout << "Types of songs you can add:" << endl
			<< "1 - Song" << endl
			<< "2 - Hiphop" << endl
			<< "3 - Rock" << endl
			<< "0 - Back to menu" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			add_song();
			break;
		case 2:
			add_hiphop();
			break;
		case 3:
			add_rock();
			break;
		case 0:
			return;
		default:
			cout << "Incorrect input" << endl;
		}
	}
}

void Menu::load_songs() {
    string buffer;
	vector<string> tokens;
	fstream f;
	try {
		f.open("Songs.txt");
	}
	catch (const exception& error) {
		cout << "File didn't open " << error.what();
		return;
	}

    while (getline(f, buffer)) {
		if (buffer == "<Song>") {
			while (getline(f, buffer)) {
				if (buffer == "</Song>") break;
				string s = buffer;
				tokens.push_back(s);
			}
			Song* new_song = new Song();
			new_song->Load(tokens);
			Songs.push_back(new_song);
			tokens.clear();
		}

		else if (buffer == "<Hiphop>") {
			while (getline(f, buffer)) {
				if (buffer == "</Hiphop>") break;
				string s = buffer;
				tokens.push_back(s);
			}
			Hiphop* new_song = new Hiphop();
			new_song->Load(tokens);
			Songs.push_back(new_song);
			tokens.clear();
        }

		else if (buffer == "<Rock>") {
			while (getline(f, buffer)) {
				if (buffer == "</Rock>") break;
				string s = buffer;
				tokens.push_back(s);
			}
			Rock* new_song = new Rock();
			new_song->Load(tokens);
			Songs.push_back(new_song);
			tokens.clear();
        }
    }
}

void Menu::save_songs(string filename) {
	fstream f;
	try {
		f.open(filename);
	}
	catch (const exception& error) {
		cout << "File didn't open " << error.what();
		return;
	}
	for (int i = 0; i < Songs.size(); i++) {
		f << Songs[i]->to_String();
	}
	cout << "Songs saved\n";
}

void Menu::menu_edit() {
    string user_input;
	int int_case;
	while (1) {
		cout << "Edit menu" << endl
			<< "1 - Add song" << endl
			<< "2 - Edit song" << endl
			<< "3 - Delete song" << endl
			<< "0 - Back to main menu" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			menu_add();
			break;
		case 2:
			menu_edit();
			break;
		case 3:
			menu_delete();
			break;
		case 0:
			return;
		default:
			cout << "Incorrect input" << endl;
		}
	}
}

void Menu::edit_song() {
    Print();
	cout << "Which song do you want to edit? (0 - back to menu): ";
	string user_input;
	int int_case = -1;
	while (1) {
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		if (int_case == 0) return;
		int_case--;

		if (int_case >= 0 && int_case < Songs.size()) {
			Songs[int_case]->menu_edit();
			break;
		}
		cout << "Incorrect input" << endl;
	}
}

void Menu::delete_song() {
    Print();
	cout << "Which song do you want to delete? (0 - back to menu): ";
	string user_input;
	int int_case = -1;
	while (1) {
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		if (int_case == 0) return;
		int_case--;
		 
		if (int_case >= 0 && int_case < Songs.size()) {
			Songs.erase(Songs.begin() + int_case);
			break;
		}
		cout << "Incorrect input" << endl;
	}
}

void Menu::menu_sort() {
	string user_input;
	int int_case;
	while (1) {
		cout << "Sort menu" << endl
			<< "1 - By release year" << endl
			<< "2 - By song length" << endl
			<< "3 - By song name" << endl
			<< "4 - By artist name" << endl
			<< "0 - Back to main menu" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			sort('y');
			break;
		case 2:
			sort('l');
			break;
		case 3:
			sort('n');
            break;
		case 4:
			sort('a');
            break;
		case 0:
			return;
		default:
			cout << "Incorrect input" << endl;
		}
	}
}

void Menu::sort(char mode) {
	vector<Song*> sorted;
	if (Songs.empty()) {
		cout << "The list is empty!" << endl;
		return;
	}

	sorted.push_back(Songs[0]);
	int i, j;
	for (i = 1; i < Songs.size(); i++) {
		for (j = 0; j < sorted.size(); j++) {
			if (mode == 'y') if (Songs[i]->get_year() < sorted[j]->get_year()) break;
			else if (mode == 'l') if (Songs[i]->get_length() < sorted[j]->get_length()) break;
			else if (mode == 'n') if (Songs[i]->get_name() < sorted[j]->get_name()) break;
			else if (mode == 'a') if (Songs[i]->get_artist() < sorted[j]->get_artist()) break;
		}

		if (j >= sorted.size())
			sorted.push_back(Songs[i]);
		else
			sorted.insert(sorted.begin() + j, Songs[i]);
	}

	cout << "List of sorted songs: " << endl;
	for (int i = 0; i < sorted.size(); i++) {
		cout << i + 1 << ". ";
		sorted[i]->Print();
		cout << endl;
	}

    menu_save(sorted, sorted.size());
}

void Menu::menu_save(vector<Song> sorted, int length) {
    string user_input;
    cout << "Want to save the list? (y/n) ";
    getline(cin, user_input);
    if (user_input[0] == 'y') {
        save_songs("Songs (modified).txt");
    }
}

void Menu::menu_filter() {
    string user_input;
	int int_case;
	while (1) {
		cout << "Filtr Menu" << endl
			<< "1 - By release year" << endl
			<< "2 - By song length" << endl
			<< "3 - By song name" << endl
			<< "4 - By artist name" << endl
            << "5 - By main genre" << endl
			<< "0 - Back to main menu" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1:
			filter('y');
			break;
		case 2:
			filter('l');
			break;
		case 3:
			filter('n');
			break;
		case 4:
			filter('a');
			break;
		case 5:
			filter('g');
			break;
		case 0:
			return;
		default:
			cout << "Incorrect input" << endl;
		}
	}
}

void Menu::filter(char mode) {
	if (Songs.empty()) {
		cout << "The list is empty!" << endl;
		return;
	}

    vector<Song*> filtered;
	string user_input;
	int i;

    if (mode == 'y') {
        cout << "Show songs released before this year: " << endl;
        cout << "(add '-' to show songs released after this year): ";
        getline(cin, user_input);
        cast_to_number(user_input, cast_int);
        if (cast_int < 0) {
            cast_int = -cast_int;
            for (i = 0; i < Songs.size(); i++) {
                if (Songs[i]->get_year() >= cast_int)
                    filtered.push_back(Songs[i]);
            }
        }
        else {            
            for (i = 0; i < Songs.size(); i++) {
                if (Songs[i]->get_year() <= cast_int)
                    filtered.push_back(Songs[i]);
            }
        }
    } else if (mode == 'l') {
        cout << "Show songs shorter than x seconds: " << endl;
        cout << "(add '-' to show songs longer than this number): ";
        getline(cin, user_input);
        cast_to_number(user_input, cast_int);
        if (cast_int < 0) {
            cast_int = -cast_int;
            for (i = 0; i < Songs.size(); i++) {
                if (Songs[i]->get_length() >= cast_int)
                    filtered.push_back(Songs[i]);
            }
        }
        else {            
            for (i = 0; i < Songs.size(); i++) {
                if (Songs[i]->get_length() <= cast_int)
                    filtered.push_back(Songs[i]);
            }
        }
    } else if (mode == 'n') {
        cout << "Input name of the song: ";
        getline(cin, user_input);
        for (i = 0; i < Songs.size(); i++) {
            if (Songs[i].get_name() == user_input)
                filtered.push_back(Songs[i]);
        }
    } else if (mode == 'a') {
        cout << "Input name of the artist: ";
        getline(cin, user_input);
        for (i = 0; i < Songs.size(); i++) {
            if (Songs[i].get_artist() == user_input)
                filtered.push_back(Songs[i]);
        }
    } else if (mode == 'g') {
        string Song_Genre = "class ";
        cout << "Input genre: ";
        getline(cin, user_input);
        Song_Genre += user_input;
        for (i = 0; i < Songs.size(); i++) {
            if (typeid(*Songs[i]).name() == Song_Genre)
                filtered.push_back(Songs[i]);
        }
    }

    cout << "List of filtered Songs: " << endl;
    for (int i = 0; i < filtered.size(); i++) {
        cout << i + 1 << ". ";
        filtered[i]->Print();
        cout << endl;
    }
}


void Menu::main_menu() {
	string user_input;
	int int_case;

	while (1) {
		cout << "Main menu" << endl
			<< "1 - Print all" << endl
			<< "2 - Sort" << endl
			<< "3 - Edit" << endl
			<< "4 - Save" << endl
			<< "5 - Load" << endl
			<< "6 - Filter" << endl //TODO: �������
			<< "0 - Exit" << endl;
		getline(cin, user_input);
		cast_to_number(user_input, int_case);
		switch (int_case) {
		case 1: 
			Print();
			break;
		case 2:
			menu_sort();
			break;
		case 3:
			menu_edit();
			break;
		case 4:
			save_songs();
			break;
		case 5:
			load_songs();
			break;
		case 6:
			menu_filter();
			break;
		case 0:
            cout << "Bye";
			return;
		default:
			cout << "Incorrect input" << endl;
		}
	}
}