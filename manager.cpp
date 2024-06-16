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
	std::getline(std::cin, tmp);
	return tmp;
}
std::string InputManager::get_recipe_text()
{

}
std::string InputManager::get_recipe_name(SQLiteDBConnection* db)
{
	const char* sqlQuery = "SELECT name FROM recipe;";
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db->get_ptr(), sqlQuery, -1, &stmt, 0);
	std::vector<std::string> names;
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		names.push_back(std::string((const char *)sqlite3_column_text(stmt, 0)));
	}
	std::string tmp;
	do {
		tmp = get_str();
		if (names.empty() == true) break;
		auto it = std::find(names.begin(), names.end(), tmp);
		if (it != names.end()) break;
	} while (true);
}
Recipe* InputManager::get_recipe(SQLiteDBConnection* db)
{
	system("cls");
	std::cout << "Введите название рецепта: ";
	/* 
	* Тут надо запомнить позицию указателя, после чего передавать ее в функцию чтения названия,
	* если название введено некорректно возращать пользователя на это место 
	*/
	std::string name = get_recipe_name(db);
}

ProductWithUnits* InputManager::get_pwu(SQLiteDBConnection* db)
{

}