//Area class written by JS, 02/27/21.

#ifndef AREA_H
#define AREA_H
#include <string>
#include <vector>
#include "PLAYER.h"
#include "ENUMS.h"
using std::string; using std::vector;

class area
{
    private:
    static vector<vector<area*>> areaMap; //Grid in which to store pointers to areas
    //for the purpose of movement.
    int areaLocationX; //Room's location along the X/east-west axis.
    int areaLocationY; //Room's location along the Y/north-south axis.
    string areaDescription; //What is displayed when entering or looking around the room.
    string areaName; //The room's official name.

    public:
    static area* getArea(int, int); //Returns an area's pointer from areaMap.
    static area* getCurrentArea(); //Returns the pointer of the current area.
    area(int, int, string); //Basic constructor; takes coordinates and area name.
    area(string); //Constructor for areas that don't fit on the map; takes area name.
    void displayArea(); //Displays the area description.
    void findExits(); //Finds any exits and outputs their locations.
    void enterArea(); //Moves the player to a given area.
    void setAreaDescription(string); //Sets the area description.
    void goDirection(eVerb); //Moves the player in a given direction.
};

#endif