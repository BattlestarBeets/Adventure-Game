#ifndef mobs_cpp
#define mobs_cpp

#include <string>

#include "mobs.hpp"

using std::string;

//mob(area, string, string, int, int); //Basic constructor ; mob(roomLocation, mobName, mobDescription, health, damage)
mob::mob(string name, string desc, string attackDesc, int health, int damage)
{
    enemyName = name;
    enemyDescription = desc;
    enemyAttackDesc = attackDesc;
    enemyHealth = health;
    enemyAttackDamage = damage;
}

mob::enemyAttack()
{
    hurtPlayer(enemyAttackDamage);
}

#endif
