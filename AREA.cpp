//Area class written by JS, 02/27/21.

#ifndef area_cpp
#define area_cpp
#include <iostream>
#include "area.hpp"
using std::cout; using std::cin; using std::string; using std::endl; using std::vector;

//Defining here to avoid linker error.
vector <vector <area*> > area::areaMap(5, vector<area*>(5));

//Displays description text and local pickups for the given area.
void area::displayArea()
{
    cout << areaDescription << endl;
    for (auto it : areaItems)
    {
        cout << "There is a(n) " << it.getItemName() << " here." << endl;
    }
    if (areaEnemy != nullptr)
    {
        cout << "There is an enemy " << areaEnemy->getEnemyName() << " here." << endl;
    }
}

//Displays the area description, moves the player, and displays the area's exits.
void area::enterArea()
{
    player* p1 = player::getPlayer();
    p1->playerLocationX = areaLocationX;
    p1->playerLocationY = areaLocationY;
    displayArea();
    findExits();
    cout << endl;
}

//Basic coordinate math on the 2D array allows us to determine if a room has exits.
void area::findExits()
{
    try
    {
        if (areaMap.at(areaLocationX).at(areaLocationY - 1) != NULL) //is the adjacent area instantiated?
        {
            cout << "To the north, there is the " <<
            areaMap.at(areaLocationX).at(areaLocationY - 1)->areaName << "." << endl;
            if (areaMap.at(areaLocationX).at(areaLocationY - 1)->locked == true)
            {
                cout << "The door to the " <<
                areaMap.at(areaLocationX).at(areaLocationY - 1)->areaName << " is locked." << endl;
            }
        }
    }
    catch (const std::out_of_range& oor)
    {
        ;
    }
    try
    {
        if (areaMap.at(areaLocationX).at(areaLocationY + 1)!=NULL)
        {
            cout << "To the south, there is the " <<
            areaMap.at(areaLocationX).at(areaLocationY + 1)->areaName << "." << endl;
            if (areaMap.at(areaLocationX).at(areaLocationY + 1)->locked == true)
            {
                cout << "The door to the " <<
                areaMap.at(areaLocationX).at(areaLocationY + 1)->areaName << " is locked." << endl;
            }
        }
    }
    catch (const std::out_of_range& oor)
    {
        ;
    }
    try
    {
        if (areaMap.at(areaLocationX + 1).at(areaLocationY)!=NULL)
        {
            cout << "To the east, there is the " <<
            areaMap.at(areaLocationX + 1).at(areaLocationY)->areaName << "." << endl;
            if (areaMap.at(areaLocationX + 1).at(areaLocationY)->locked == true)
            {
                cout << "The door to the " <<
                areaMap.at(areaLocationX + 1).at(areaLocationY)->areaName << " is locked." << endl;
            }
        }
    }
    catch (const std::out_of_range& oor)
    {
        ;
    }
    try
    {
        if (areaMap.at(areaLocationX - 1).at(areaLocationY)!=NULL)
        {
            cout << "To the west, there is the " <<
            areaMap.at(areaLocationX - 1).at(areaLocationY)->areaName << "." << endl;
            if (areaMap.at(areaLocationX - 1).at(areaLocationY)->locked == true)
            {
                cout << "The door to the " <<
                areaMap.at(areaLocationX - 1).at(areaLocationY)->areaName << " is locked." << endl;
            }
        }
    }
    catch (const std::out_of_range& oor)
    {
        ;
    }
}

//Sets the description of the area. Call upon area creation and if you
//change something about the room.
void area::setAreaDescription(string description)
{
    areaDescription = description;
}

void area::fightSequence()
{
    player* p1 = player::getPlayer();
    if (areaEnemy != nullptr)
    {
        areaEnemy->enemyDeathCheck();
    }
    if (areaEnemy != nullptr)
    {
        areaEnemy->enemyAttack();
    }
    if (p1->playerHealth > 0)
    {
        p1->showHealth();
    }
}

//Moves the player in a given direction.
void area::goDirection(eVerb direction)
{
    switch (direction)
    {
        case north:
        try
        {
            if (areaMap.at(areaLocationX).at(areaLocationY - 1) == NULL)
            {
                cout << "You can't go that way!" << endl;
            }
            else if (areaMap.at(areaLocationX).at(areaLocationY - 1)->locked == true)
            {
                cout << "The door is locked." << endl;
            }
            else
            {
                areaMap.at(areaLocationX).at(areaLocationY - 1)->enterArea();
            }
        }
        catch (const std::out_of_range& oor)
        {
            cout << "You can't go that way!" << endl;
        }
        break;
        case south:
        try
        {
            if (areaMap.at(areaLocationX).at(areaLocationY + 1) == NULL)
            {
                cout << "You can't go that way!" << endl;
            }
            else if (areaMap.at(areaLocationX).at(areaLocationY + 1)->locked == true)
            {
                cout << "The door is locked." << endl;
            }
            else
            {
                areaMap.at(areaLocationX).at(areaLocationY + 1)->enterArea();
            }
        }
        catch (const std::out_of_range& oor)
        {
            cout << "You can't go that way!" << endl;
        }
        break;
        case east:
        try
        {
            if (areaMap.at(areaLocationX + 1).at(areaLocationY) == NULL)
            {
                cout << "You can't go that way!" << endl;
            }
            else if (areaMap.at(areaLocationX + 1).at(areaLocationY)->locked == true)
            {
                cout << "The door is locked." << endl;
            }
            else
            {
                areaMap.at(areaLocationX + 1).at(areaLocationY)->enterArea();
            }
        }
        catch (const std::out_of_range& oor)
        {
            cout << "You can't go that way!" << endl;
        }
        break;
        case west:
        try
        {
            if (areaMap.at(areaLocationX - 1).at(areaLocationY) == NULL)
            {
                cout << "You can't go that way!" << endl;
            }
            else if (areaMap.at(areaLocationX - 1).at(areaLocationY)->locked == true)
            {
                cout << "The door is locked." << endl;
            }
            else
            {
                areaMap.at(areaLocationX - 1).at(areaLocationY)->enterArea();
            }
        }
        catch (const std::out_of_range& oor)
        {
            cout << "You can't go that way!" << endl;
        }
        break;
        default:
        cout << "Something is terribly wrong." << endl;
    }
}

void area::addItem(pickup item)
{
    areaItems.push_back(item);
}


void area::addEnemy(mob* enemy)
{
    areaEnemy = enemy;
}


//Basic constructor for an area.
area::area(int X, int Y, string name)
{
    areaLocationX = X;
    areaLocationY = Y;
    areaMap[X][Y] = this;
    areaName = name;
    locked = false;
    vector<pickup> temp;
    areaItems = temp;
    areaEnemy = NULL;
}

//Constructor for locked rooms.
area::area(int X, int Y, string name, bool lock)
{
    areaLocationX = X;
    areaLocationY = Y;
    areaMap[X][Y] = this;
    areaName = name;
    locked = lock;
    vector<pickup> temp;
    areaItems = temp;
    areaEnemy = NULL;
}

//Constructor for areas that don't fit on the map.
area::area(string name)
{
    areaName = name;
    vector<pickup> temp;
    areaItems = temp;
    areaEnemy = nullptr;
}

//Use for areas the player is not in.
area* area::getArea(int X, int Y)
{
    try 
    {
        return areaMap.at(X).at(Y);
    }
    catch (const std::out_of_range& oor)
    {
        cout << "Something's wrong with the getArea function." << endl;
        return nullptr;
    }
}

//Use for the area the player is currently in.
area* area::getCurrentArea()
{
    player* p1 = player::getPlayer();
    return areaMap[p1->playerLocationX][p1->playerLocationY];
}

#endif