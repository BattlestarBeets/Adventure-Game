//Parser written by JS, 03/12/21.

#ifndef PARSER_CPP
#define PARSER_CPP
#include "PARSER.h"
using std::cout; using std::cin; using std::string; using std::endl; using std::vector;

//Converts inputs to lowercase for case-insensitive parsing.
string lc(string s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

//Creates the verbMap used in the parser proper to parse the strings. Synonyms are
//defined here.
std::map<string, eVerb> makeVerbMap()
{
    std::map<string, eVerb> verbMap;
    verbMap["look"] = look; verbMap["lookaround"] = look;
    verbMap["north"] = north; verbMap["n"] = north;
    verbMap["south"] = south; verbMap["s"] = south;
    verbMap["east"] = east; verbMap["e"] = east;
    verbMap["west"] = west; verbMap["w"] = west;
    verbMap["take"] = take; verbMap["get"] = take; verbMap["pickup"] = take;
    return verbMap;
}

//For some reason you have to make a constructor function and then call it, you can't
//just construct a map out-of-line. C++, why.
std::map<string, eVerb> verbMap = makeVerbMap();

//The main event. Takes words from userInput(), strips out filler words, and tells
//the system what to do with the words that are left (which should ideally be a single
//verb and an optional noun). Again, will be added to as we add things to do.
bool parseInput(vector<string> sentence)
{
    player* p1 = player::getPlayer();
    area* currentArea = area::getCurrentArea();
    for (int i = 0; i < sentence.size();)
    {
        if (sentence[i] == "at" || sentence[i] == "go" || sentence[i] == "the" || 
        sentence[i] == "a" || sentence[i] == "an")
        {
            sentence.erase(sentence.begin() + i);
        }
        else if ((sentence[i] == "look" && sentence[i+1] == "around" ) || 
        (sentence[i] == "pick" && sentence[i+1] == "up"))
        {
            sentence[i] += sentence[i+1];
            sentence.erase(sentence.begin() + i + 1);
            i++;
        }
        else
        {
            i++;
        }
    }
    switch(verbMap[sentence[0]]) //Checks the first relevant word input by the user.
    {
        case look:
        //Once we have objects coded, we'll be able to have code to look at those objects.
        //We don't, so we don't. Default looks around the current room. ("look
        //[currentArea->areaName]" should also look around the current room, but there's no
        //point coding that until we have a non-default case.)
        currentArea->displayArea();
        break;
        case north:
        currentArea->goDirection(north);
        break;
        case south:
        currentArea->goDirection(south);
        break;
        case east:
        currentArea->goDirection(east);
        break;
        case west:
        currentArea->goDirection(west);
        break;
        default:
        cout << "I didn't understand that command." << endl;
        return false;
        break;
    }
    return true;
}

void userInput()
{
    bool successful = false;
    do
    {
        cout << "What do you do?" << endl;
        string input;
        getline(cin, input);
        input = lc(input);
        vector<string> sentence;
        string temp = "";
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != ' ')
            {
                temp += input[i];
            }
            else
            {
                sentence.push_back(temp);
                temp = "";
            }
            if (i == (input.length() - 1))
            {
                sentence.push_back(temp);
            }
        }
        successful = parseInput(sentence);
    }
    while (!successful);
}
#endif