#include <iostream>
#include <stdlib.h>
#include "player.hpp"
using namespace std;

//Functionality is to verify the warriors health bar 
void showHealth()
{
    player* p1 = player::getPlayer();
    if (p1->playerHealth <= p1->getMaxHP() && p1->playerHealth >= (p1->getMaxHP() * 0.75))
    {
        system("Color 0A");
        cout << "Your health: " <<
        p1->playerHealth << "/" << p1->getMaxHP() << endl;
        system("Color 07");
    }
    else if (p1->playerHealth <= (p1->getMaxHP() * 0.75) && p1->playerHealth >= (p1->getMaxHP() * 0.25))
    {
        system("Color 0E");
        cout << "Health: " <<
        p1->playerHealth << "/" << p1->getMaxHP() << endl;
        system("Color 07");
    }
    else if (p1->playerHealth <= (p1->getMaxHP() * 0.25) && p1->playerHealth >= 0)
    {
        system("Color 0C");
        cout << "Health: " <<
        p1->playerHealth << "/" << p1->getMaxHP() << endl;
        system("Color 07");
    }
}