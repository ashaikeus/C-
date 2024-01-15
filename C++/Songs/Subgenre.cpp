#include "Subgenre.h"

Subgenre::Subgenre() {
	name = "Genre name";
	description = "...";
}

Subgenre::~Subgenre() {}

string Subgenre::get_name() {
    return name;
}
string Subgenre::get_description() {
    return description;
}

void Subgenre::set_name(string new_) {
    name = new_;
}
void Subgenre::set_description(string new_) {
    description = new_;
}

// string Subgenre::to_String() {
// 	string output = "";
// 	output += "Genre: " + name + " (" + description + ")";
// 	return output;
// }

void Subgenre::Fill(string name, bool add_desc) {
	string user_input;

	if (name == "") {
		cout << " Name: ";
		getline(cin, user_input);
		set_name(user_input);
	} else {
		set_name(name);
	}

	if (add_desc) {
		cout << " Enter genre description: ";
		getline(cin, user_input);
		set_description(user_input);
	}
}