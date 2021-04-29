#ifndef mobs_cpp
#define mobs_cpp

#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include "mobs.hpp"

using std::string; using std::cout; using std::endl;

//mob(area, string, string, int, int); //Basic constructor ; mob(roomLocation, mobName, mobDescription, health, damage)
mob::mob(string name, string desc, string attackDesc, int health, int damage)
{
    enemyName = name;
    enemyDescription = desc;
    enemyAttackDesc = attackDesc;
    enemyHealth = health;
    enemyAttackDamage = damage;
    enemyDrop = nullptr;
}

mob::mob(string name, string desc, string attackDesc, int health, int damage, pickup* mobDrop)
{
    enemyName = name;
    enemyDescription = desc;
    enemyAttackDesc = attackDesc;
    enemyHealth = health;
    enemyAttackDamage = damage;
    enemyDrop = mobDrop;
}

void mob::enemyDeathCheck()
{
    area* currentArea = area::getCurrentArea();
    player* p1 = player::getPlayer();
    if (enemyHealth <= 0)
    {
        cout << "You have slain the " << enemyName << "!" << endl;
        if (enemyDrop != nullptr)
        {
            currentArea->addItem(*enemyDrop);
            cout << "The " << enemyName << " dropped a " << enemyDrop->getItemName() << "!" << endl;
        }
        if (enemyName == "butler")
        {
            cout << "The Butler collapses after you deal the final blow. He disintegrates \n"
                "and behind him you see the safe that he had been trying to protect. You approach\n"
                "the safe and notice it isn't even locked. Was he trying to close it before you walked\n"
                "in? The rusty safe creaks open as you pull on the handle and there you see stacks of\n"
                "gold bricks and a variety of test tubes with different elixirs in them. You grab\n"
                "them all and leave. It's day light now and you feel like you've been gone for days.\n"
                "With a sigh relief and a backpack full of riches you leave and go on your merry way."
                << endl;
            p1->winGame();
        }
        currentArea->areaEnemy = nullptr;
    }
    else
    {
        cout << "Enemy health: " << enemyHealth << endl;
    }
}

void mob::enemyAttack()
{
    player* p1 = player::getPlayer();
    srand(time(NULL));
    int damage = rand() % enemyAttackDamage + (enemyAttackDamage / 2);
    cout << "The " << enemyName << " " << enemyAttackDesc << " you for " << damage << " damage!" << endl;
    p1->hurtPlayer(damage);
}

#endif
