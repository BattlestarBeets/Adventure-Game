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
}

mob::mob(string name, string desc, string attackDesc, int health, int damage, *pickup mobDrop)
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
    if (enemyHealth >= 0)
    {
        this = NULL;
        currentArea->areaEnemy = NULL;
        cout << "You have slain the " << enemyName << "!" << endl;
    }
}

void mob::enemyAttack()
{
    player* p1 = player::getPlayer();
    srand(time(NULL));
    int damage = rand() % enemyAttackDamage + (enemyAttackDamage / 2);
    p1->hurtPlayer(damage);
    cout << "The " << enemyName << " " << enemyAttackDesc << " for " << damage << " damage!" << endl;
}

#endif
