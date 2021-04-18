//Player class written by JS, 03/03/21.

#ifndef player_cpp
#define player_cpp
#include <iostream>
#include <stdlib.h>
#include "player.hpp"
using std::cout; using std::cin; using std::string; using std::endl;

//Defining here to avoid linker error.
player* player::p1;
player::player(){}

//Sets player name. Call upon creation and forget about it.
void player::setPlayerName()
{
    setPlayerJob(student);
}

//Sets player's job and maxHealth. Call upon creation (as student) and when the
//player picks up their starting weapon.
void player::setPlayerJob(eJob inJob)
{
    playerJob = inJob;
    switch (playerJob)
    {
        case student: playerHealth = 20; playerStats[maxHealth] = 20;
        break;
        case mage: case cultist: playerStats[maxHealth] = 20;
        break;
        case rogue: playerStats[maxHealth] = 30;
        break;
        case warrior: playerStats[maxHealth] = 40;
        break;
    }
}

//Causes HP damage.
void player::hurtPlayer(int damage)
{
    playerHealth -= damage;
    if (playerHealth <= 0) //If damage exceeds HP, die
    {
        player::killPlayer();
    }
}

//Heals HP damage.
void player::healPlayer(int healing)
{
    if (playerHealth + healing <= playerStats[maxHealth]) //Check if overheal
    {
        playerHealth += healing;
    }
    else
    {
        playerHealth = playerStats[maxHealth]; //No overheal.
    }
}

//Causes corruption damage.
void player::corruptPlayer(int damage)
{
    playerCorruption += damage;
    if (playerCorruption >= 13) //Lucky 13 is the threshold. 13 or over? Die.
    {
        player::badEnd();
    }
}

//Cures corruption damage.
void player::purifyPlayer(int healing)
{
    if (playerCorruption - healing >= 0) //No negative corruption.
    {
        playerCorruption = 0;
    }
    else
    {
        playerCorruption -= healing;
    }
}

void player::showHealth()
{
    if (playerHealth <= playerStats[0] && playerHealth >= (playerStats[0] * 0.75))
    {
        cout << "Your health: " << playerHealth << "/" << playerStats[0] << endl;
    }
    else if (playerHealth <= (playerStats[0] * 0.75) && playerHealth >= (playerStats[0] * 0.25))
    {
        cout << "Health: " << playerHealth << "/" << playerStats[0] << endl;
    }
    else if (playerHealth <= (playerStats[0] * 0.25) && playerHealth >= 0)
    {
        cout << "Health: " << playerHealth << "/" << playerStats[0] << endl;
    }
}

//Mods stats; can be positive or negative.
void player::modPlayerStat(eStat stat, int modification)
{
    playerStats[stat] += modification;
}

//This will be expanded to account for what killed you. For now, Dark Souls style.
void player::killPlayer()
{
    cout << "Congratulations! You died." << endl;
    exit(0);
}

//This will be expanded to account for what corrupted you.
void player::badEnd()
{
    cout << "You have suffered a fate worse than death." << endl;
    exit(0);
}

//Call this in order to refer to the player.
player* player::getPlayer()
{
    if (!p1)
    {
        p1 = new player;
    }
    return p1;
}

#endif