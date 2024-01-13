#include "functions.h"
using namespace std;

void cast_to_number(string user_input, int& user_int) {
	try {
		user_int = stoi(user_input);
	}
	catch (const exception& error) {
		cout << "Error " << error.what() << endl;
		user_int = -1;
	}
}

void cast_to_bool(string user_input, bool& user_bool) {
    if (user_input.length() == 1) {
        if (user_input[0] == '1') user_bool = true;
        if (user_input[0] == '0') user_bool = false;
    }
}

string bts(bool user_bool) {
	string result = "0";
	if (user_bool) result = "1";
	return result;
}

string two_digitize(int number) {
	if (number % 10 == number) return "0" + to_string(number);
	else return to_string(number);
}