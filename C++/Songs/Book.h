#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
#include "Song.h"

class Book {
protected:
    string name;
    string author;
    int pages;
public:
    Book();
    ~Book();

    string get_name();
    string get_author();
    int get_pages();

    void set_name(string);
    void set_author(string);
    void set_pages(int);
};

class Audiobook : public Book, Song {
    friend class Menu;
private:
    vector<string> voice_actors;
public:
    Audiobook();
    ~Audiobook();

    vector<string> get_voice_actors();
    int get_length();

    void set_voice_actors(vector<string>);
    void set_pages(int);

    void edit_menu();
    void edit_voice_actors();

    void Fill();
    void Print();
    string to_String();
    void Load(vector<string>);
};