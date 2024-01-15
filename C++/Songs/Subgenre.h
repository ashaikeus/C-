#pragma once
#include "functions.h"

class Subgenre {
	friend class Song;
	friend class Rock;
	friend class Hiphop;
	// friend class Menu;
private:
	string name;
	string description;
public:
	Subgenre();
	~Subgenre();

	string get_name();
	string get_description();

	void set_name(string);
	void set_description(string);

	void Fill(string, bool);
	// string to_String();
	// void Edit();
	// string For_Save();
};