#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

class Song {
protected:
    string name;
    string artist;
    string album;
    string label;
    string language;
    int year;
    // string date;
    int length;  // in seconds
    bool is_explicit;
    vector<string> genres;
    vector<string> featuring;
    vector<string> lyricists;
    vector<string> nominations;
    vector<string> used_in;
public:
    Song();
    ~Song();

    string get_name();
    string get_artist();
    string get_album();
    string get_label();
    string get_language();
    int get_year();
    int get_length();
    bool get_is_explicit();
    vector<string> get_genres();
    vector<string> get_featuring();
    vector<string> get_lyricists();
    vector<string> get_nominations();
    vector<string> get_used_in();

    void set_name(string);
    void set_artist(string);
    void set_album(string);
    void set_label(string);
    void set_language(string);
    void set_year(int);
    void set_length(int);
    void set_is_explicit(bool);
    void set_genres(vector<string>);
    void set_featuring(vector<string>);
    void set_lyricists(vector<string>);
    void set_nominations(vector<string>);
    void set_used_in(vector<string>);

    void edit_vectors(char);
    void add_genre(string);
    void add_featuring(string);
    void add_lyricist(string);
    void add_nomination(string);
    void add_used_in(string);

    double calc_typicalness();

	void Print();
	string to_String();
	void Fill();
	void Load(vector<string>);
	void edit_menu();
};