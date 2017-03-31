#include "ConsoleMenu.h"
#include "CommonHelper.h"

using namespace ConsoleMenu;

MenuItem::MenuItem()
{
	name = "none";
	info = "none";
	action = NULL;
}

MenuItem::MenuItem(string itemName, string itemInfo, MenuItemAction _action)
{
	name = itemName;
	info = itemInfo;
	action = _action;
}

MenuItem::~MenuItem()
{
	//name.clear();
	//info.clear();
	action = NULL;
}

bool MenuItem::HandleInput(string input)
{
	bool result = input == name;
	if (result)
		action(name);
	return result;
}

string MenuItem::GetItemInfo()
{
	return this ? info : "";
}

string MenuItem::GetItemName()
{
	return this ? name : "";
}

void MenuItem::SetItemInfo(string newInfo)
{
	info = newInfo;
}

void MenuItem::SetItemName(string newName)
{
	name = newName;
}

bool DefaultOnInputFunc(string input)
{
	return false;
}

Menu::Menu(string menuTitle)
{
	title = menuTitle;
	OnInput = &DefaultOnInputFunc;
	//menuItems = new vector<MenuItem>();
}

Menu::Menu(string menuTitle, MenuOnInputFunc _onInputFunc)
{
	title = menuTitle;
	OnInput = _onInputFunc;
}

Menu::~Menu()
{
	//Clear();
}

void Menu::Clear()
{
	/*for each (MenuItem item in menuItems)
	{
		item.
	}*/
	menuItems.clear();
	//title.clear();
}

void Menu::AddItem(string name, string info, MenuItemAction _action)
{
	menuItems.push_back(MenuItem(name, info, _action));
}

void Menu::DeleteItem(string name)
{
	MenuItem *item = nullptr;
	unsigned int i = 0;
	while (i < menuItems.size() && !item)
	{
		if (menuItems[i].GetItemName() == name)
		{
			item = &menuItems[i];
			break;
		}
		++i;
	}

	if (item == nullptr)
		PrintError("DeleteItem(): item wasn't found", "Menu");
	else
		menuItems.erase(menuItems.begin() + i);
}

void Menu::DrawNames()
{
	string fill = "------";
	cout << fill << title << fill << endl;
	int i = 1;
	for each(MenuItem item in menuItems)
		cout << i++ << ". " << item.GetItemName() << " - " << item.GetItemInfo() << endl;
	cout << fill << title << fill << endl;
}

string Menu::Display()
{
	string input;
	DrawNames();
	cin >> input;
	MenuItem *triggered = nullptr;
	int i = 0;
	if (menuItems.size() > 0)
	{
		while (i < (int)menuItems.size() && !triggered)
		{
			if (menuItems[i].HandleInput(input))
			{
				triggered = &menuItems[i];
				break;
			}
			++i;
		}
	}
	string result = triggered->GetItemName();
	if (!triggered && !OnInput(input))
		PrintError("wrong input. try again", "Menu");
	return result;
}