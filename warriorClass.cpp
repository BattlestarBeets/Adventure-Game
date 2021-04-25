#ifndef warriorClass_cpp
#define warriorClass_cpp

#include "mageClass.hpp"
#include "player.hpp"
#include "mobs.hpp"

#include <random>
#include <string>
#include <iostream>
#include <ctime>
using std::cout; using std::endl;

/* ATTACKS */
void slash(mob* target)
{
	srand(time(NULL));
	int damage = rand() % 3 + 2;
	target->enemyHealth -= damage;
	cout << "You slash the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void lunge(mob* target)
{
	srand(time(NULL));
	int damage = rand() % 5 + ;
	target->enemyHealth -= damage;
	cout << "You lunge at the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void heavySwin(mob* target)
{
	srand(time(NULL));
	int damage = rand() % 8 + 3;
	target->enemyHealth -= damage;
	cout << "You swing at the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

}

#endif