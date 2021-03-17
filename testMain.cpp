#include "AREA.h"
#include "PLAYER.h"
#include "PARSER.h"
#include "NEWAREA.h"

int main()
{
    areaSetup();
    player* p1 = player::getPlayer();
    p1->setPlayerName();
    area* startRoom = area::getArea(2, 3);
    startRoom->enterArea();
    while (true)
    {
        userInput();
    }
    return 0;
}