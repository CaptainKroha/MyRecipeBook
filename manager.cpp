#include "manager.h"
#include "items.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include "visualizer.h"
#include <codecvt>

std::string InputManager::wchar_to_utf8(const wchar_t* wstr)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	std::string utf_8_str = converter.to_bytes(wstr);
	return utf_8_str;
}

std::wstring InputManager::utf8_to_wchar(const char* str) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	std::wstring wstr = converter.from_bytes(str);
	return wstr;
}

void RecipesManager::create_recipe()
{
	new_recipe = InputManager::get_recipe(db);

}

int InputManager::get_int()
{
	std::string tmp;
	std::cin >> tmp;
	if (tmp == "0") return 0;
	return atoi(tmp.c_str());
}
std::string InputManager::get_str()
{
	std::string tmp;
	std::cin.ignore(1024, '\n');
	std::getline(std::cin, tmp);
	return tmp;
}
std::string InputManager::get_recipe_text()
{
	return std::string("");
}
std::string InputManager::get_recipe_name(DBConnectionBase* db)
{
	std::vector<std::string> names;
	db->get_recipes_names(names);
	std::string tmp;
	do {
		tmp = get_str();
		if (names.empty() == true) break;
		auto it = std::find(names.begin(), names.end(), tmp);
		if (it != names.end()) break;
	} while (true);
	return tmp;
}
Recipe* InputManager::get_recipe(DBConnectionBase* db)
{
	system("cls");
	std::cout << "¬ведите название рецепта: ";
	/* 
	* “ут надо запомнить позицию указател€, после чего передавать ее в функцию чтени€ названи€,
	* если название введено некорректно возращать пользовател€ на это место 
	*/
	std::string name = get_recipe_name(db);
	std::cout << "¬ведите список продуктов: ";
	return nullptr;
}

ProductWithUnits* InputManager::get_pwu(DBConnectionBase* db)
{
	return nullptr;
}