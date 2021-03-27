//Pickup class written by JS, 03/24/21.
#ifndef pickup_h
#define pickup_h

#include <string>
#include <vector>
#include "enums.h"
#include "area.h"
using std::string; using std::vector;

class pickup
{
    protected:
    int itemInventorySpace; //The space an item occupies in the player's inventory.
    eUse itemFunction; //What the item does.
    int itemHeal; //If the item is a cure, this is how much it heals.
    area* itemLock; //If the item is a key, this is the room it unlocks.
    string itemDescription; //The item's descriptor text.
    string itemDisplayName; //The item's in-game name; "Rusted Sword," for instance.

    public:
    pickup(area, eUse, string, string); //Basic constructor.
    void takeItem(); //Puts the item in the player's inventory.
    void useItem(); //Uses an item's special ability. Keys unlock, food is eaten, etc.
    void destroyItem(); //Destroys an item when that (destructible) item is used.
    string getItemDesc() {return itemDescription;}
    string getItemName() {return itemDisplayName;}
};

class weapon: public pickup
{
    private:
    int weaponDamage;

    public:
    weapon(area, string, string, int); //Basic constructor.
    void takeItem(); //Overloads so that picking up a weapon equips it rather than
    //putting it in the inventory proper.
    void equipWeapon();
};

#endif