#ifndef enums_hpp
#define enums_hpp

//This file stores various enums. Using unscoped enum instead of enum class so enum values
//can index arrays without using static_cast.

//The player's main stats: knowledge::mage, might::warrior, trickery::rogue,
//depravity::cultist. maxHealth is determined by class: mage/cultist/student 20,
//rogue 30, warrior 40. The correspondence between the jobs and their relevant stats
//is deliberate, in case we want to use unscoped enum equality in some capacity.
enum eJob {student = 0, mage = 1, warrior = 2, rogue = 3, cultist = 4};
enum eStat {maxHealth = 0, knowledge = 1, might = 2, trickery = 3, depravity = 4};

//Enum to store verbs. Will be added to as we add more things to do. Cardinal directions are
//totally verbs, guys.
enum eVerb
{
    north = 1, south = 2, east = 3, west = 4,
    take = 5,
    look = 6,
    equip = 7,
    use = 8
};

//Enum to store usable item types.
enum eUse {cure = 1, key = 2, page = 3, weapon = 4};

#endif