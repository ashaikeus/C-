#pragma once
#include <typeinfo>
#include "Hiphop.h"
#include "Rock.h"

class Menu {
private:
    vector<Song*> Songs;
    void Print();

    void add_song();
    void add_hiphop();
    void add_rock();

    void menu_add();
    void load_songs();
    void save_songs(string);
    void menu_edit();

    void edit_song();
    void delete_song();

    void menu_sort();
    void sort(char);
    void menu_save(vector<Song*>, int);

    void menu_filter();
    void filter(char);

public:
    Menu();
    ~Menu();
    void main_menu();
};