#ifndef mageClass_cpp
#define mageClass_cpp

#include "mageClass.hpp"
#include "player.hpp"
#include "mobs.hpp"


#include <string>


void fireball(mob target)
{
	int damage = 5;

	target.enemyHealth -= damage;

}



#endif