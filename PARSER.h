//This file exists to avoid linker errors.

#ifndef parser_h
#define parser_h
#include <locale>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "area.h"
#include "player.h"
#include "enums.h"
using std::string; using std::vector;

string lowercase(string);
std::map<string, eVerb> makeVerbMap();
bool parseInput(vector<string> sentence);
void userInput();

#endif