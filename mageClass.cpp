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

/* ATTACKS */
void fireballSpell(mob target)
{
	srand(time(NULL));
	int damage = rand() % 5 + 3;
	target.enemyHealth -= damage;
	cout << "You scorch the " << target.getEnemyName() << " for " << damage << " damage!" << endl;
}

void lightningBoltSpell(mob target)
{
	srand(time(NULL));
	int damage = rand() % 7 + 3;
	target.enemyHealth -= damage;
	cout << "You strike the " << target.getEnemyName() << " for " << damage << " damage!" << endl;
}

void iceShardSpell(mob target)
{
	srand(time(NULL));
	int damage = rand() % 9 + 2;
	target.enemyHealth -= damage;
	cout << "You freeze the " << target.getEnemyName() << " for " << damage << " damage!" << endl;
}

/* HEALING */
//void healingSpell()
//{
//	srand(time(NULL));
//	int healing = rand() % 7 + 4;
//	//playerHealth=+ healing
//	cout << "You heal yourself from " << healing << " damage!" << endl;
//}



#endif