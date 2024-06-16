#include "manager.h"
#include "items.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	std::cout << "Введите название рецепта: ";
	/* 
	* Тут надо запомнить позицию указателя, после чего передавать ее в функцию чтения названия,
	* если название введено некорректно возращать пользователя на это место 
	*/
	std::string name = get_recipe_name(db);
	std::cout << name;
	return nullptr;
}

ProductWithUnits* InputManager::get_pwu(DBConnectionBase* db)
{
	return nullptr;
}