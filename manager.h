#pragma once
#include "dbclass.h"
#include "items.h"
#include <string>
#include <vector>

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
	static std::string get_str();
	static std::string get_recipe_text();
	static std::string get_recipe_name(DBConnectionBase* db);
	static Recipe* get_recipe(DBConnectionBase* db);
	static ProductWithUnits* get_pwu(DBConnectionBase* db);
};