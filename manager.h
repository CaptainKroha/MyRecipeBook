#pragma once
#include "dbclass.h"
#include "items.h"
#include <string>
#include <vector>

class RecipesManager {
	SQLiteDBConnection* db{ nullptr };
	Recipe* new_recipe{ nullptr };

public:
	RecipesManager(SQLiteDBConnection* _db): db(_db) { }
	void create_recipe();

};

class InputManager {
public:
	static int get_int();
	static std::string get_str();
	static std::string get_recipe_text();
	static std::string get_recipe_name(SQLiteDBConnection* db);
	static Recipe* get_recipe(SQLiteDBConnection* db);
	static ProductWithUnits* get_pwu(SQLiteDBConnection* db);
};