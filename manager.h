#pragma once
#include "dbclass.h"
#include "items.h"
#include <string>
#include <vector>
#include <list>

class RecipesManager {
	DBConnectionBase* db{ nullptr };
	Recipe* new_recipe{ nullptr };

public:
	RecipesManager(DBConnectionBase* _db): db(_db) { }
	void create_recipe();

};

class InputManager {
public:
	static int get_int();
	static int get_int(std::wstring addition);
	static std::wstring get_str();
	static std::wstring get_str(std::wstring);
	static std::string get_recipe_text();
	static std::wstring get_recipe_name(DBConnectionBase* db);
	static Recipe* get_recipe(DBConnectionBase* db);
	static ProductWithUnits* get_pwu(DBConnectionBase* db, std::vector<std::wstring>& names, std::vector<std::wstring>& units);
	static void get_pwu_list(DBConnectionBase* db, std::list<ProductWithUnits>& pwu_list);
	static std::string wchar_to_utf8(const wchar_t* wstr);
	static std::wstring utf8_to_wchar(const char* str);
};