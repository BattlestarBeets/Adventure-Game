//Pickup class written by JS, 03/24/21.

#ifndef pickup_cpp
#define pickup_cpp
#include "pickup.h"
#include "player.h"
#include <iostream>
using std::vector; using std::cout; using std::cin; using std::string; using std::endl;

//Places an item in the player's inventory and banishes its map instance to the Shadow Realm.
void pickup::takeItem()
{
    player* p1 = player::getPlayer();
    p1->playerInventory.push_back(*this);
    cout << "Picked up " << itemDisplayName << "!" << endl;
    area* currentArea = area::getCurrentArea();
    for (auto it : currentArea->areaItems)
    {
        if (it.itemDisplayName == this->itemDisplayName)
        {
            currentArea->areaItems.erase(it);
            break;
        }
    }
}

//Finds and removes the item currently being used from the player inventory.
void pickup::destroyItem()
{
    player* p1 = player::getPlayer();
    for (auto it : p1->playerInventory)
    {
        if (it.itemDisplayName == this->itemDisplayName)
        {
            p1->playerInventory.erase(it);
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
    area* currentArea = area::getCurrentArea();
    switch (itemFunction)
    {
        case cure:
        p1->healPlayer(itemHeal);
        cout << "You consume the " << itemDisplayName << ". Your health is now " <<
        p1->playerHealth << endl;
        destroyItem();
        break;
        case key:
        if (area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY - 1] == itemLock)
        {
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY - 1]->locked = false;
            cout << "The door to the " <<
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY - 1]->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY - 1]->enterArea();
            break;
        }
        else if (area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY + 1] == itemLock)
        {
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY + 1]->locked = false;
            cout << "The door to the " <<
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY + 1]->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap[currentArea->areaLocationX][currentArea->areaLocationY + 1]->enterArea();
            break;
        }
        else if (area::areaMap[currentArea->areaLocationX + 1][currentArea->areaLocationY] == itemLock)
        {
            area::areaMap[currentArea->areaLocationX + 1][currentArea->areaLocationY]->locked = false;
            cout << "The door to the " <<
            area::areaMap[currentArea->areaLocationX + 1][currentArea->areaLocationY]->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap[currentArea->areaLocationX + 1][currentArea->areaLocationY]->enterArea();
            break;
        }
        else if (area::areaMap[currentArea->areaLocationX - 1][currentArea->areaLocationY] == itemLock)
        {
            area::areaMap[currentArea->areaLocationX - 1][currentArea->areaLocationY]->locked = false;
            cout << "The door to the " <<
            area::areaMap[currentArea->areaLocationX - 1][currentArea->areaLocationY]->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap[currentArea->areaLocationX - 1][currentArea->areaLocationY]->enterArea();
            break;
        }
        else
        {
            cout << "You can't use that key here." << endl;
            currentArea->enterArea();
        }
        break;
        default:
        cout << "useItem function has encountered an error." << endl;
        break;
    }
}

pickup::pickup(area location, eUse function, string desc, string name)
{
    location.areaItems.push_back(*this);
    itemFunction = function;
    itemDescription = desc;
    itemDisplayName = name;
}

void weapon::takeItem()
{
    equipWeapon();
}

void weapon::equipWeapon()
{
    player* p1 = player::getPlayer();
    p1->playerWeapon = this;
    cout << "Equipped " << itemDisplayName << "!" << endl;
}

weapon::weapon(area location, string desc, string name, int dmg)
{
    location.areaWeapon = this;
    itemDescription = desc;
    itemDisplayName = name;
    weaponDamage = dmg;
}

#endif