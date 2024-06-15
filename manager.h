#pragma once
#include "dbclass.h"
class RecipesManager {
	SQLiteDBConnection* db{ nullptr };

public:
	RecipesManager(SQLiteDBConnection* _db): db(_db) { }

};