#ifndef mobs_cpp
#define mobs_cpp

#include <string>

#include "mobs.hpp"

using std::string;

//mob(area, string, string, int, int); //Basic constructor ; mob(roomLocation, mobName, mobDescription, health, damage)
mob:: mob(string name, string desc, int health, int damage)
{
    enemyName = name;
    enemyDescription = desc;
    enemyHealth = health;
    enemyAttackDamage = damage;


}

#endif