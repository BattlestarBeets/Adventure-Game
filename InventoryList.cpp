#ifndef inventorylist_cpp
#define inventorylist_cpp

#include "InventoryList.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::string; using std::endl;

void getInventory()
{
	player* p1 = player::getPlayer();
	int i = 0;
	for (int j = 0; j < p1->playerInventory.size(); j++)
	{
		cout << j + 1 << ": " << p1->playerInventory[j].getItemName() << endl;
		i++;
	}
	int playerChoice;
	if (i != 0)
	{
		cout << "Enter a number to view the item, or enter 0 to exit." << endl;
		cin >> playerChoice;
		//Needs input sanitation.
		if (playerChoice != 0)
		{
			string use;
			cout << p1->playerInventory.at(playerChoice - 1).getItemDesc() << endl;
			cout << "Use the " << p1->playerInventory.at(playerChoice - 1).getItemName() << "?" << endl;
			while (use[0] != 'y' && use[0] != 'n' && use[0] != 'N' && use[0] != 'Y')
			{
				getline(cin >> std::ws, use);
				if (use[0] == 'y' || use[0] == 'Y')
				{
					p1->playerInventory.at(playerChoice - 1).useItem();
				}
				else if (use[0] == 'n' || use[0] == 'N')
				{
					getInventory();
				}
				else
				{
					cout << "Please enter Y or N." << endl;
				}
			}
		}
	}
	else
	{
		cout << "You have nothing in your inventory." << endl;
	}
}

#endif