#include "parser.hpp"
#include "newArea.hpp"

int main()
{
    areaSetup();
    player* p1 = player::getPlayer();
    p1->setPlayerJob(student);
    area* startRoom = area::getArea(2, 3);
    startRoom->enterArea();
    while (p1->won == false && p1->lost == false)
    {
        userInput();
    }
    std::cout << "Enter any input to exit." << std::endl;
    std::string close;
    std::cin >> close;
    return 0;
}