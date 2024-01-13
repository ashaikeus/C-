#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <stdbool.h>

void cast_to_number(string user_input, int& user_int);
void cast_to_bool(string user_input, bool& user_bool);
string bts(bool user_bool);
string two_digitize(int number);