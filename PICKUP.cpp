//Pickup class written by JS, 03/24/21.

#ifndef pickup_cpp
#define pickup_cpp
#include "pickup.hpp"
#include "player.hpp"
#include <iostream>
using std::vector; using std::cout; using std::cin; using std::string; using std::endl;

//Places an item in the player's inventory and banishes its map instance to the Shadow Realm.
void pickup::takeItem()
{
    player* p1 = player::getPlayer();
    area* currentArea = area::getCurrentArea();
    if (itemFunction == weapon)
    {
        equipWeapon();
    }
    else
    {
        p1->playerInventory.push_back(*this);
        cout << "Picked up " << itemDisplayName << "!" << endl;
    }
    int i = 0;
    for (auto it : currentArea->areaItems)
    {
        if (it.itemDisplayName == this->itemDisplayName)
        {
            currentArea->areaItems.erase(currentArea->areaItems.begin() + i);
            break;
        }
        i++;
    }
    if (itemDisplayName == "sword")
    {
        currentArea->setAreaDescription("You stand in the storage room. You took the sword;\n"
        "nothing else here interests you.");
    }
    if (itemDisplayName == "necklace")
    {
        cout << "The necklace doesn't actually do anything, but it sure looks cool. \n"
        "Maybe you can get a few bucks for it." << endl;
        currentArea->setAreaDescription("You stand in the graveyard. It's spooky out here.");
    }
    if (itemDisplayName == "book")
    {
        currentArea->setAreaDescription("You stand in the library. None of the other books\n"
        "look very interesting.");
    }
}

//Finds and removes the item currently being used from the player inventory.
void pickup::destroyItem()
{
    player* p1 = player::getPlayer();
    int j = 0;
    for (auto it : p1->playerInventory)
    {
        int i = 0;
        if (it.itemDisplayName == this->itemDisplayName)
        {
            p1->playerInventory.erase(p1->playerInventory.begin() + i);
            j++;
            break;
        }
        i++;
    }
    if (j == 0)
    {
        cout << "Could not destroy item." << endl;
    }
}

//Uses the current item. Depending on the item type, this could mean a lot of things.
//Currently, you eat it. Because it's an apple.
void pickup::useItem()
{
    player* p1 = player::getPlayer();
    area* currentArea = area::getCurrentArea();
    switch (itemFunction)
    {
        case misc:
        cout << "That's not a usable item." << endl;
        case cure:
        p1->healPlayer(itemHeal);
        cout << "You consume the " << itemDisplayName << ". Your health is now " <<
        p1->playerHealth << endl;
        destroyItem();
        break;
        case key:
        if (area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY - 1) == itemLock)
        {
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY - 1)->locked = false;
            cout << "The door to the " <<
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY - 1)->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY - 1)->enterArea();
            break;
        }
        else if (area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY + 1) == itemLock)
        {
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY + 1)->locked = false;
            cout << "The door to the " <<
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY + 1)->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap.at(currentArea->areaLocationX).at(currentArea->areaLocationY + 1)->enterArea();
            break;
        }
        else if (area::areaMap.at(currentArea->areaLocationX + 1).at(currentArea->areaLocationY) == itemLock)
        {
            area::areaMap.at(currentArea->areaLocationX + 1).at(currentArea->areaLocationY)->locked = false;
            cout << "The door to the " <<
            area::areaMap.at(currentArea->areaLocationX + 1).at(currentArea->areaLocationY)->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap.at(currentArea->areaLocationX + 1).at(currentArea->areaLocationY)->enterArea();
            break;
        }
        else if (area::areaMap.at(currentArea->areaLocationX - 1).at(currentArea->areaLocationY) == itemLock)
        {
            area::areaMap.at(currentArea->areaLocationX - 1).at(currentArea->areaLocationY)->locked = false;
            cout << "The door to the " <<
            area::areaMap.at(currentArea->areaLocationX - 1).at(currentArea->areaLocationY)->areaName <<
            "is now unlocked!" << endl;
            destroyItem();
            area::areaMap.at(currentArea->areaLocationX - 1).at(currentArea->areaLocationY)->enterArea();
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

pickup::pickup(eUse function, string name, string desc, int variable) //pickup* itemName[1](roomName, itemType, itemName, itemDescription, healingAmount) //put this in NEWAREA.CPP
{
    itemFunction = function;
    itemJob = student;
    itemDescription = desc;
    itemDisplayName = name;
    if (function == cure)
    {
        itemHeal = variable;
    }
    else if (function == weapon)
    {
        weaponDamage = variable;
    }
}

pickup::pickup(eUse function, eJob job, string name, string desc, int variable) //pickup* itemName[1](roomName, itemType, itemName, itemDescription, healingAmount) //put this in NEWAREA.CPP
{
    itemFunction = function;
    itemJob = job;
    itemDescription = desc;
    itemDisplayName = name;
    if (function == cure)
    {
        itemHeal = variable;
    }
    else if (function == weapon)
    {
        weaponDamage = variable;
    }
}

void pickup::equipWeapon()
{
    player* p1 = player::getPlayer();
    p1->playerWeapon = this;
    if (p1->getJob() == student)
    {
        cout << "You are now a mage! If there is a creature in your current location,\n"
        "you can type 'cast fireball' to give it what for." << endl;
    }
    p1->setPlayerJob(itemJob);
    cout << "Equipped " << itemDisplayName << "!" << endl;
}

#endif