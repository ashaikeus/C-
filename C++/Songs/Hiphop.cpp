#include "Hiphop.h"

Hiphop::Hiphop() {
    language = "English";
    is_by_black = 0;
    is_by_woman = 0;
    is_very_fast = 0;
    swear_words = 0;
}

Hiphop::~Hiphop() {
    cout << "Hiphop song object destroyed" << endl;
}

string Hiphop::get_language() {
    return language;
};
bool Hiphop::get_is_by_black() {
    return is_by_black;
};
bool Hiphop::get_is_by_woman() {
    return is_by_woman;
};
bool Hiphop::get_is_very_fast() {
    return is_very_fast;
};
int Hiphop::get_swear_words() {
    return swear_words;
};

void Hiphop::set_language(string new_language) {
    if new_language.length() == 0 {
        cout << "Language can't be empty" << endl;
        return;
    }
    language = new_language;
};

void Hiphop::set_is_by_black(bool is_black) {
    is_by_black = is_black;
};
void Hiphop::set_is_by_woman(bool is_woman) {
    is_by_woman = is_woman;
};
void Hiphop::set_is_very_fast(bool is_fast) {
    is_very_fast = is_fast;
};
void Hiphop::set_swear_words(int swears) {
    if swears < 0 {
        cout << "you're insane, how can you swear " << swears << " times in the song? impossible" << endl;
        return;
    }
    if swears > 0 {
        is_explicit = true;
    }
    swear_words = swears;
};

void Hiphop::Print() {
    Song::Print();
    cout << " Language: " << language << endl <<
        " Is made by a black person: " << is_by_black << endl <<
        " Is made by a woman: " << is_by_woman << endl <<
        " Is very fast: " << is_very_fast << endl <<
        " Contains " << swear_words << " swear words" << endl;
}
void Hiphop::to_String() {
    string end_result = "";
    end_result += "<Hiphop>\n";
    end_result += name + "\n" +
                artist + "\n" +
                album + "\n" +
                label + "\n";
    end_result += to_string(year) + "\n" + to_string(length) + "\n" + to_string(is_explicit) + "\n";
    end_result += "<Genres>\n";
	for (int i = 0; i < genres.size(); i++) {
		end_result += genres[i] + "\n";
	}
	end_result += "</Genres>\n";
    end_result += "<Featuring>\n";
	for (int i = 0; i < featuring.size(); i++) {
		end_result += featuring[i] + "\n";
	}
	end_result += "</Featuring>\n";
    end_result += "<Lyricists>\n";
	for (int i = 0; i < lyricists.size(); i++) {
		end_result += lyricists[i] + "\n";
	}
	end_result += "</Lyricists>\n";
    end_result += "<Nominations>\n";
	for (int i = 0; i < nominations.size(); i++) {
		end_result += nominations[i] + "\n";
	}
	end_result += "</Nominations>\n";
    end_result += "<Used in>\n";
	for (int i = 0; i < used_in.size(); i++) {
		end_result += used_in[i] + "\n";
	}
	end_result += "</Used in>\n";

    end_result += bts(is_by_black) + "\n" + bts(is_by_woman) + "\n" + bts(is_very_fast) + "\n";
    end_result += to_string(swear_words) + "\n";
    end_result += "</Hiphop>";
}