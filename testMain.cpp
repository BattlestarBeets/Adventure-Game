#include "parser.hpp"
#include "newArea.hpp"

int main()
{
    areaSetup();
    player* p1 = player::getPlayer();
    p1->setPlayerJob(student);
    area* startRoom = area::getArea(2, 3);
    startRoom->enterArea();
    for(;;)
    {
        userInput();
    }
    return 0;
}