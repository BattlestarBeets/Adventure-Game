//Instantiates areas at the beginning of the game so the main remains tidy.
#ifndef newarea_cpp
#define newarea_cpp
#include "newArea.hpp"

void areaSetup()
{
    area* startRoom = new area (2, 3, "Foyer");
    startRoom->setAreaDescription(
    "You're standing in the entry hall. There's not much in here\n"
    "- some candelabras, a rug, a hell of a lot of cobwebs."
    );
    area* swordRoom = new area (2, 2, "Storage room");
    swordRoom->setAreaDescription(
    "You're standing in the storage room. There's a ton of junk\n"
    "in here. Also, a sword."
    );
    area* graveyard = new area (2, 4, "Graveyard");
    graveyard->setAreaDescription(
    "You're standing in the graveyard. Spooky. There's tombstones\n"
    "everywhere. One of them has a strange necklace on it."
    );
    area* kitchen = new area (1, 3, "Kitchen");
    kitchen->setAreaDescription(
    "You're standing in the kitchen. There's a knife block with a\n"
    "butcher's knife stuck in it - looks wickedly sharp."
    );
    area* library = new area (3, 3, "Library");
    library->setAreaDescription(
    "You're standing in the library. Thick dust covers the shelves\n"
    "and books, except for one tome sitting proudly on a pedestal."
    );
}
#endif