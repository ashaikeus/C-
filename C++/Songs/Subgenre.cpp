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


void Subgenre::Fill() {
	string user_input;

	cout << " Name: ";
	getline(cin, user_input);
	set_name(user_input);

	cout << " Description: ";
	getline(cin, user_input);
	set_description(user_input);
}