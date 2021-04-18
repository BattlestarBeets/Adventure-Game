//Player class written by JS, 03/03/21. 

class pickup;

#ifndef player_hpp
#define player_hpp
#include <string>
#include "pickup.hpp"
#include "enums.hpp"
using std::string; using std::vector;

class player
{
    private:
    static player* p1; //Making this class a singleton so the instance can be called
    //from anywhere.
    player(); //Private constructor for the singleton; prevents erroneous reconstruction.
    string playerName; //Entered by player at beginning of game.
    eJob playerJob; //The character's class.
    unsigned int playerStats[5]; //Stores the player's stats.
    friend class pickup;
    friend class area;

    public:
    unsigned int playerHealth; //The character's health meter. Stores current health, not max.
    unsigned int playerCorruption; //The character's corruption meter. This serves
    //as a sort of secondary health bar, related less to physical damage
    //and more to mental or moral harm. Starts at 0, goes to 13.
    static player* getPlayer(); //Use this to point to p1, the player.
    int playerLocationX; //Character's location along the X-axis.
    int playerLocationY; //Character's location along the Y-axis.
    void showHealth();
    int getMaxHP() {return playerStats[0];}
    eJob getJob() {return playerJob;}
    void setPlayerName(); //Sets the player's name.
    void setPlayerJob(eJob); //Sets the player's job when they select their
    //starting weapon.
    void hurtPlayer(int); //Lowers player's health.
    void healPlayer(int); //Increases player's health up to max.
    void corruptPlayer(int); //Increases player's corruption.
    void purifyPlayer(int); //Decreases player's corruption.
    void modPlayerStat(eStat, int); //Modifies the specified stat.
    void killPlayer(); //Game over.
    void badEnd(); //Game over (corruption edition).
    vector <pickup> playerInventory;
    pickup* playerWeapon;
};

#endif