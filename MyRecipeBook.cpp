# include <iostream>
# include "dbclass.h"
# include <sqlite3.h>
# include <string>

const char* path_head = "D:/my_dir_for_learning/projects/MyRecipeBook/";

int main()
{
	setlocale(0, "RU_ALL");
	std::string path{ path_head };
	path += "dbfiles/recipe_book_db.db";
	try {
		
		SQLiteDBConnection* connection = new SQLiteDBConnection(path);
		connection->open();
	}
	catch(int) {
		std::cerr << "Ошибка открытия базы данных" << std::endl;
	}
	return 0;
}