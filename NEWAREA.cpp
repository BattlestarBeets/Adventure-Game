//Instantiates areas at the beginning of the game so the main remains tidy.
#ifndef NEWAREA_CPP
#define NEWAREA_CPP
#include "NEWAREA.h"

void areaSetup()
{
    area* startRoom = new area (3, 4, "Foyer");
    startRoom->setAreaDescription(
    "You're standing in the entry hall. There's not much in here\n"
    "- some candelabras, a rug, a hell of a lot of cobwebs."
    );
    area* swordRoom = new area (3, 3, "Storage room");
    swordRoom->setAreaDescription(
    "You're standing in the storage room. There's a ton of junk\n"
    "in here. Also, a sword."
    );
    area* graveyard = new area (3, 5, "Graveyard");
    graveyard->setAreaDescription(
    "You're standing in the graveyard. Spooky. There's tombstones\n"
    "everywhere. One of them has a strange necklace on it."
    );
    area* kitchen = new area (2, 4, "Kitchen");
    kitchen->setAreaDescription(
    "You're standing in the kitchen. There's a knife block with a\n"
    "butcher's knife stuck in it - looks wickedly sharp."
    );
    area* library = new area (4, 4, "Library");
    library->setAreaDescription(
    "You're standing in the library. Thick dust covers the shelves\n"
    "and books, except for one tome sitting proudly on a pedestal."
    );
}
#endif