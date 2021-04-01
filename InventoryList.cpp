#ifndef inventorylist_hpp
#define inventorylist_hpp

#include "InventoryList.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::string; using std::endl;

void getInventory()
{
	player* p1 = player::getPlayer();

	for (int i = 0; i < p1->playerInventory.size(); i++)
	{
		cout << i + 1 << ": " << p1->playerInventory[i].getItemName() << endl;
	}
	cout << "Enter a number to view the item, or enter ESC to exit." << endl;

}

#endif