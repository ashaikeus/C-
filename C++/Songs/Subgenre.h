#pragma once
#include "functions.h"

class Subgenre {
	friend class Song;
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

	void Fill();
	string to_String();
	void Edit();
	string For_Save();
};