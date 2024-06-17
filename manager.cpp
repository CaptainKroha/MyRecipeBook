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

Recipe* InputManager::get_recipe(DBConnectionBase* db)
{
	system("cls");
	std::wstring name, recipe_text;
	std::list<ProductWithUnits> pwu_list;
	/*
	* “ут надо запомнить позицию указател€, после чего передавать ее в функцию чтени€ названи€,
	* если название введено некорректно возращать пользовател€ на это место
	*/
	name = get_recipe_name(db);
	std::wcout << L"¬ведите список продуктов: " << std::endl;
	get_pwu_list(db, pwu_list);
	// std::wcout << L"¬ведите текст рецепта: ";
	return nullptr;
}

int InputManager::get_int()
{
	std::wstring tmp;
	std::wcin >> tmp;
	if (tmp == L"0") return 0;
	return atoi(wchar_to_utf8(tmp.c_str()).c_str());
}

int InputManager::get_int(std::wstring addition)
{
	std::wcout << addition;
	return get_int();
}

std::wstring InputManager::get_str()
 {
	std::wstring tmp;
	if(std::wcin.peek() == L'\n')
		std::wcin.ignore(1024, L'\n');
	std::getline(std::wcin, tmp);
	return tmp;
}

std::wstring InputManager::get_str(std::wstring addition)
{
	std::wcout << addition;
	return get_str();
}

std::string InputManager::get_recipe_text()
{
	return std::string("");
}

std::wstring InputManager::get_recipe_name(DBConnectionBase* db)
{
	std::vector<std::wstring> names;
	db->get_names(L"recipe", names);
	std::wstring tmp;
	do {
		tmp = get_str(L"¬ведите название рецепта: ");
		if (names.empty() == true) break;
		auto it = std::find(names.begin(), names.end(), tmp);
		if (it != names.end()) break;
	} while (true);
	return tmp;
}

ProductWithUnits* InputManager::get_pwu(DBConnectionBase* db, std::vector<std::wstring>& names, std::vector<std::wstring>& units)
{
	VisualizerBase* visualizer = new ListVisualizer;
	std::wstring name;
	int unit_id;
	double qty;
	// ввод названи€ продукта динамически
	name = get_str(L"¬ведите название продукта: ");
	unit_id = visualizer->show_list(units);
	unit_id = db->get_id_by_name(L"units", units[unit_id - 1]);
	system("cls");
	qty = get_int(L"¬ведите количество ингредиента: ");
	std::wcout << name << " " << unit_id << " " << qty << std::endl;
	return new ProductWithUnits(name, unit_id, qty);
}

void InputManager::get_pwu_list(DBConnectionBase* db, std::list<ProductWithUnits>& pwu_list)
{
	std::vector<std::wstring> names, units;
	db->get_names(L"products", names);
	db->get_names(L"units", units);
	pwu_list.push_back(*get_pwu(db, names, units));
}