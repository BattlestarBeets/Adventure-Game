#ifndef mageClass_cpp
#define mageClass_cpp

#include "mageClass.hpp"
#include "player.hpp"
#include "mobs.hpp"
#include "newArea.hpp"

#include <random>
#include <string>
#include <iostream>
using std::cout; using std::endl;

/* ATTACKS */
void fireballSpell(mob* target)
{
	int damage = rand() % 5 + 3;
	target->enemyHealth -= damage;
	cout << "You scorch the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void lightningBoltSpell(mob* target)
{
	int damage = rand() % 4 + 7;
	target->enemyHealth -= damage;
	cout << "You shock the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

void iceShardSpell(mob* target)
{
	int damage = rand() % 3 + 9;
	target->enemyHealth -= damage;
	cout << "You freeze the " << target->getEnemyName() << " for " << damage << " damage!" << endl;
}

/* HEALING */
void healingSpell()
{
	player* p1 = player::getPlayer();
	int healing = rand() % 7 + 4;
	p1->healPlayer(healing);
	cout << "You heal yourself of " << healing << " damage!" << endl;
}

#endif