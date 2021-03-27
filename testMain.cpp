#include "parser.hpp"
#include "newArea.hpp"

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