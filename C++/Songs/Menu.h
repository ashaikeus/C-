#pragma once
#include <typeinfo>
#include "Hiphop.h"
#include "Rock.h"
#include "Book.h"

class Menu {
private:
    vector<Song*> Songs;
    vector<Subgenre*> Subgenres;
    void Print();

    void add_song();
    void add_hiphop();
    void add_rock();
    void add_audiobook();

    void menu_add();
    void load_songs();
    void save_songs(string);
    void menu_edit();

    void menu_edit_song();
    void delete_song();

    void menu_sort();
    void sort(char);
    void menu_save(vector<Song*>, int);

    void menu_filter();
    void filter(char);

    void load_genres();
    void print_genres();
    // void menu_edit_genres();
    // void edit_genres();

public:
    Menu();
    ~Menu();
    void main_menu();
};