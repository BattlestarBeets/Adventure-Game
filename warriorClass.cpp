#ifndef warriorClass_cpp
#define warriorClass_cpp

#include "mageClass.hpp"
#include "player.hpp"
#include "mobs.hpp"
#include "newArea.hpp"

#include <random>
#include <string>
#include <iostream>
#include <ctime>
using std::cout; using std::endl;

/* ATTACKS */
void slash(mob* target)
{
	int damage = rand() % 7 + 5;
	target->enemyHealth -= damage;
	cout << "You slash the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void lunge(mob* target)
{
	int damage = rand() % 9 + 5;
	target->enemyHealth -= damage;
	cout << "You lunge at the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void heavySwing(mob* target)
{
	int damage = rand() % 11 + 5;
	target->enemyHealth -= damage;
	cout << "You swing at the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

#endif