#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>
#include "dbclass.h"

void SQLiteDBConnection::get_recipes_names(std::vector<std::string>& names) {
	const char* sqlQuery = "SELECT name FROM recipe;";
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, sqlQuery, -1, &stmt, 0);
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		names.push_back(std::string((const char*)sqlite3_column_text(stmt, 0)));
	}
}