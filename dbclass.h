#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <string.h>
#include <vector>

class DBConnectionBase {
protected:
	std::string path{ "" };
	DBConnectionBase(std::string& _path) {
		path = _path;
	}
public:
	virtual void open() = 0;
	virtual void get_recipes_names(std::vector<std::string>& names) = 0;
};

class SQLiteDBConnection : public DBConnectionBase {
	sqlite3* db{ nullptr };

public:
	SQLiteDBConnection(std::string& _path) : DBConnectionBase(_path)
	{ }
	~SQLiteDBConnection() {
		if (db) sqlite3_close(db);
	}
	virtual void open() override
	{
		int rc = sqlite3_open(path.c_str(), &db);
		if (rc) throw 1;
	}
	sqlite3* get_ptr() { return db; }

	void get_recipes_names(std::vector<std::string>& names) override;

};