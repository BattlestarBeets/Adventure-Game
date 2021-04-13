#ifndef mageClass_cpp
#define mageClass_cpp

#include "mageClass.hpp"
#include "player.hpp"
#include "mobs.hpp"

#include <random>
#include <string>
#include <iostream>
#include <ctime>
using std::cout; using std::endl;


void fireballSpell(mob target)
{
	srand(time(NULL));
	int damage = rand() % 5 + 3;
	target.enemyHealth -= damage;
	cout << "You scorch the " << target.getEnemyName() << " for " << damage << " damage!" << endl;
}



#endif