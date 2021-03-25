//Pickup class written by JS, 03/24/21.

#include "PICKUP.h"
#include "PLAYER.h"
#include <iostream>
using std::vector; using std::cout; using std::cin; using std::string; using std::endl;

//Places an item in the player's inventory and banishes its map instance to the Shadow Realm.
void pickup::takeItem()
{
    player::playerInventory.push_back(*this);
    itemLocationX = -1;
    itemLocationY = -1;
    cout << "Picked up " << itemDisplayName << "!" << endl;
}

//Finds and removes the item currently being used from the player inventory. The item still
//exists in the Shadow Realm, but who cares.
void pickup::destroyItem()
{
    for (vector<pickup>::iterator it = player::playerInventory.begin();
    it != player::playerInventory.end(); ++it)
    {
        if (it->itemDisplayName == this->itemDisplayName)
        {
            player::playerInventory.erase(it);
            break;
        }
    }
    cout << "Could not destroy item." << endl;
}

//Uses the current item. Depending on the item type, this could mean a lot of things.
//Currently, you eat it. Because it's an apple.
void pickup::useItem()
{
    player* p1 = player::getPlayer();
    switch (itemFunction)
    {
        case cure:
        p1->healPlayer(itemHeal);
        cout << "You consume the " << itemDisplayName << ". Your health is now " <<
        p1->playerHealth << endl;
        destroyItem();
        break;
        default:
        cout << "useItem function has encountered an error." << endl;
        break;
    }
}

void weapon::equipWeapon()
{
    player::playerWeapon = *this;
    itemLocationX = -1;
    itemLocationY = -1;
    cout << "Equipped " << itemDisplayName << "!" << endl;
}