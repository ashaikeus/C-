#pragma once
#include "Song.h"

class Rock : public Song {
private:
    bool has_distorted_guitar;  // distorted electric
    bool has_clean_guitar;  // acoustic or clean electric
    bool has_vocal;
    bool has_growls;
public:
    Rock();
    ~Rock();

    bool get_has_distorted_guitar();
    bool get_has_clean_guitar();
    bool get_has_vocal();
    bool get_has_growls();

    void set_has_distorted_guitar(bool);
    void set_has_clean_guitar(bool);
    void set_has_vocal(bool);
    void set_has_growls(bool);

    double calc_typicalness();

    void Print();
	string to_String();
	void Fill();
	void Load(vector<string>);
	void edit_menu();
};