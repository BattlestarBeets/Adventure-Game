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
		do
		{
			cout << "Enter a number to view the item, or enter 0 to exit." << endl;
			cin >> playerChoice;
			if (playerChoice != static_cast<int>(playerChoice))
			{
				cout << "Invalid entry." << endl;
			}
		}
		while (playerChoice != static_cast<int>(playerChoice));
		if (playerChoice != 0)
		{
			try
			{
				pickup chosenItem = p1->playerInventory.at(playerChoice - 1);
				cout << chosenItem.getItemDesc() << endl;
				cout << "Use the " << chosenItem.getItemName() << "?" << endl;
				string use;
				while (use[0] != 'y' && use[0] != 'n' && use[0] != 'N' && use[0] != 'Y')
				{
					getline(cin >> std::ws, use);
					if (use[0] == 'y' || use[0] == 'Y')
					{
						chosenItem.useItem();
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
	        catch (const std::out_of_range& oor)
			{
				cout << "No such item." << endl;
				getInventory();
			}
		}
	}
	else
	{
		cout << "You have nothing in your inventory." << endl;
	}
}

#endif