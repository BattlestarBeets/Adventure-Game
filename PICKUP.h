//Pickup class written by JS, 03/24/21.
#ifndef PICKUP_H
#define PICKUP_H

#include <string>
#include <vector>
#include "ENUMS.h"
using std::string; using std::vector;

class pickup
{
    protected:
    int itemLocationX; //Item's current location; the room matching these values will display
    //the item on the floor. When picked up, these are set to -1/-1.
    int itemLocationY;
    int itemInventorySpace; //The space an item occupies in the player's inventory.
    eUse itemFunction; //What the item does.
    int itemHeal; //If the item is a cure, this is how much it heals.
    string itemDescription; //The item's descriptor text.
    string itemDisplayName; //The item's in-game name; "Rusted Sword," for instance.

    public:
    void takeItem(); //Puts the item in the player's inventory.
    void useItem(); //Uses an item's special ability. Keys unlock, food is eaten, etc.
    void destroyItem(); //Destroys an item when that (destructible) item is used.
};

class weapon: protected pickup
{
    private:
    int atkValue;

    public:
    void equipWeapon();
};

#endif