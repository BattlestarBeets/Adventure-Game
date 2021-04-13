class mob;

#ifndef mobs_hpp
#define mobs_hpp

#include <string>

#include "area.hpp"
#include "pickup.hpp"

using std::string;

class mob
{

private:
	
	string enemyName;
	string enemyDescription;
	string enemyAttackDesc;
	

	pickup* enemyDrop;


public:
	mob(string, string, string, int, int); //Basic constructor ; mob(mobName, mobDescription, attackDesc, health, damage)
	mob(string, string, int, int, pickup*); //Basic constructor ; mob(mobName, mobDescription, health, damage, mobDrop)

	int enemyHealth;
	int enemyAttackDamage;

	void enemyDeathCheck();
	void enemyAttack();

	string getEnemyName() { return enemyName; }

};




#endif