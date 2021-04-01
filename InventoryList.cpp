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
	int i = 0;
	for (int j = 0; i < p1->playerInventory.size(); i++)
	{
		cout << j + 1 << ": " << p1->playerInventory[i].getItemName() << endl;
		i++;
	}
	int playerChoice;
	while (playerChoice != 0)
	{
		if (i != 0)
		{
			cout << "Enter a number to view the item, or enter 0 to exit." << endl;
			cin >> playerChoice;
			if (playerChoice != 0)
			{
				char use;
				cout << p1->playerInventory[playerChoice - 1].getItemDesc() << endl;
				cout << "Use the " << p1->playerInventory[playerChoice - 1].getItemName() << "?" << endl;
				cin.get(use);
				if (use == 'y')
				{
					p1->playerInventory[playerChoice - 1].useItem();
				}
				else if (use == 'n')
				{
					getInventory();
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "You have nothing in your inventory." << endl;
			break;
		}
	}
}

#endif