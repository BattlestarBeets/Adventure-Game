//Area class written by JS, 02/27/21.

class pickup;

#ifndef area_hpp
#define area_hpp
#include <string>
#include <vector>
#include "pickup.hpp"
#include "player.hpp"
#include "enums.hpp"
using std::string; using std::vector;

class area
{
    private:
    static vector <vector <area*> > areaMap; //Grid in which to store pointers to areas
    //for the purpose of movement.
    int areaLocationX; //Room's location along the X/east-west axis.
    int areaLocationY; //Room's location along the Y/north-south axis.
    string areaDescription; //What is displayed when entering or looking around the room.
    string areaName; //The room's official name.
    bool locked; //If the doors to the room are locked, true. Else, false.
    friend class pickup;

    public:
    static area* getArea(int, int); //Returns an area's pointer from areaMap.
    static area* getArea(string); //Returns an area's pointer from areaMap (overload).
    static area* getCurrentArea(); //Returns the pointer of the current area.
    area(int, int, string); //Basic constructor; takes coordinates and area name.
    area(string); //Constructor for areas that don't fit on the map.
    area(int, int, string, bool); //Constructor for locked rooms. Additionally takes lock.
    void displayArea(); //Displays the area description.
    void findExits(); //Finds any exits and outputs their locations.
    void enterArea(); //Moves the player to a given area.
    void setAreaDescription(string); //Sets the area description.
    void goDirection(eVerb); //Moves the player in a given direction.
    vector <pickup> areaItems; //Vector containing any usable items or other pickups
    //in the current room.
    void addItem(pickup);
};

#endif