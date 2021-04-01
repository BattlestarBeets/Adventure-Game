//Parser written by JS, 03/12/21.

#ifndef parser_cpp
#define parser_cpp
#include "parser.hpp"
#include "InventoryList.hpp"
using std::cout; using std::cin; using std::string; using std::endl; using std::vector;

//Converts inputs to lowercase for case-insensitive parsing.
string lowercase(string s)
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
    verbMap["look"] = look;
    verbMap["north"] = north; verbMap["n"] = north;
    verbMap["south"] = south; verbMap["s"] = south;
    verbMap["east"] = east; verbMap["e"] = east;
    verbMap["west"] = west; verbMap["w"] = west;
    verbMap["take"] = take; verbMap["get"] = take; verbMap["pickup"] = take;
    verbMap["equip"] = equip; verbMap["wield"] = equip; verbMap["wear"] = equip; verbMap["puton"] = equip;
    verbMap["use"] = use; verbMap["eat"] = use; verbMap["consume"] = use; verbMap["read"] = use;
    verbMap["drink"] = use;
    verbMap["inventory"] = inventory; verbMap["i"] = inventory;
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
        sentence[i] == "a" || sentence[i] == "an" || sentence[i] == "to")
        {
            sentence.erase(sentence.begin() + i);
        }
        else if ((sentence[i] == "pick" && sentence[i+1] == "up") || (sentence[i] == "put" &&
        sentence[i+1] == "on"))
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
        default:
        cout << "I didn't understand that command." << endl;
        return false;
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
        case look:
        if (sentence.size() == 1 || sentence[1] == "around")
        {
            currentArea->displayArea();
        }
        else
        {
            bool looked = false;
            for (auto it : currentArea->areaItems)
            {
                if (lowercase(it.getItemName()) == sentence[1])
                {
                    cout << it.getItemDesc() << endl;
                    looked = true;
                    break;
                }
            }
            if (looked == false)
            {
                cout << "Nothing interesting there." << endl;
            }
        }
        break;
        //Default looks around the current room. If an item name is entered and that item is in the room,
        //returns the item description.
        case take:
        if (sentence.size() != 1)
        {
            bool taken = false;
            for (auto it : currentArea->areaItems)
            {
                if (lowercase(it.getItemName()) == sentence[1])
                {
                    it.takeItem();
                    taken = true;
                    break;
                }
            }
            if (taken == false)
            {
                cout << "You can't take that." << endl;
            }
        }
        else
        {
            cout << "Take what?" << endl;
        }
        break;
        //Checks if the item name entered matches an item in the current room. If it does, item is picked up.
        case inventory:
        getInventory();
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
        getline(cin >> std::ws, input);
        input = lowercase(input);
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