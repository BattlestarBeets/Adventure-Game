//Pickup class written by JS, 03/24/21.
#ifndef pickup_hpp
#define pickup_hpp

class area;

#include <string>
#include <vector>
#include "enums.hpp"
#include "area.hpp"
using std::string; using std::vector;

class pickup
{
    private:
    eUse itemFunction; //What the item does.
    unsigned int itemHeal; //If the item is a cure, this is how much it heals.
    unsigned int weaponDamage; //If the item is a weapon, this is its base damage.
    eJob itemJob; //If the item is a weapon, this is the class it is used by.
    area* itemLock; //If the item is a key, this is the room it unlocks.
    string itemDescription; //The item's descriptor text.
    string itemDisplayName; //The item's in-game name; "Rusted Sword," for instance.

    public:
    pickup(eUse, string, string, int); //Basic constructor.
    pickup(eUse, eJob, string, string, int); //Weapon constructor.
    pickup(eUse, string, string, int, int); //Key constructor.
    void takeItem(); //Puts the item in the player's inventory.
    void useItem(); //Uses an item's special ability. Keys unlock, food is eaten, etc.
    void destroyItem(); //Destroys an item when that (destructible) item is used.
    void equipWeapon(); //Equips a weapon-type pickup to the character's weapon slot.
    string getItemDesc() {return itemDescription;}
    string getItemName() {return itemDisplayName;}
};

#endif