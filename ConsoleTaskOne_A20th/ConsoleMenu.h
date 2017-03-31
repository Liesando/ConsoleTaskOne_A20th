#pragma once

#include "string"
#include "vector"

using namespace std;

namespace ConsoleMenu
{
	//typedef void(*MenuItemAction(string menuItemName));
	using MenuItemAction = void(*)(string);
	
	class MenuItem
	{
	private:
		string name, info;
		MenuItemAction action;

	public:
		operator bool() const
		{
			return this != nullptr;
		}
		inline string GetItemName();
		inline void SetItemName(string newName);

		inline string GetItemInfo();
		inline void SetItemInfo(string newInfo);

		MenuItem();
		MenuItem(string itemName, string itemInfo, MenuItemAction _action);
		~MenuItem();
		bool HandleInput(string input);
	};

	using MenuOnInputFunc = bool(*)(string input);

	class Menu
	{
	private:
		string title;
		vector<MenuItem> menuItems;
		MenuOnInputFunc OnInput;

		void DeleteItemByID(int id);
		void DrawNames();

	public:
		Menu(string menuTitle);
		Menu(string menuTitle, MenuOnInputFunc _onInputFunc);
		~Menu();
		void AddItem(string name, string info, MenuItemAction _action);
		void DeleteItem(string name);
		void Clear();

		string Display();
	};
}