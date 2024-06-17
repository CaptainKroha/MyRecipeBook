#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>
#include "dbclass.h"
#include "manager.h"

void SQLiteDBConnection::get_names(std::wstring table_name, std::vector<std::wstring>& names)
{
	std::wstring sqlQuery{ L"SELECT name FROM " + table_name + L";" }, name;
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, InputManager::wchar_to_utf8(sqlQuery.c_str()).c_str(), -1, &stmt, 0);
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		const unsigned char* name1 = sqlite3_column_text(stmt, 0);
		name = InputManager::utf8_to_wchar(reinterpret_cast<const char*>(name1));
		names.push_back(name);
	}
	sqlite3_finalize(stmt);
}

int SQLiteDBConnection::get_id_by_name(std::wstring table_name, std::wstring name)
{
	int id(0);
	std::wstring sqlQuery{ L"SELECT id FROM " + table_name + L" WHERE name = \"" + name + L"\";" };
	sqlite3_stmt* stmt;
	std::string request = InputManager::wchar_to_utf8(sqlQuery.c_str());
	sqlite3_prepare_v2(db, request.c_str(), -1, &stmt, 0);
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		id = sqlite3_column_int(stmt, 0);
	}
	sqlite3_finalize(stmt);
	return id;
}

std::wstring SQLiteDBConnection::get_name_by_id(std::wstring table_name, int id)
{
	std::wstring name{ L"" };
	std::wstring sqlQuery{ L"SELECT name FROM " + table_name + L" WHERE id = " + std::to_wstring(id) + L";" };
	sqlite3_stmt* stmt;
	std::string request = InputManager::wchar_to_utf8(sqlQuery.c_str());
	sqlite3_prepare_v2(db, request.c_str(), -1, &stmt, 0);
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		const unsigned char* name1 = sqlite3_column_text(stmt, 0);
		name = InputManager::utf8_to_wchar(reinterpret_cast<const char*>(name1));
	}
	sqlite3_finalize(stmt);
	return name;
}
