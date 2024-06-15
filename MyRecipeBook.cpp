# include <iostream>
# include "dbclass.h"
# include <sqlite3.h>
#include <string>
#include "visualizer.h"
#include <windows.h>
#include "manager.h"

const char* path_head = "D:/my_dir_for_learning/projects/MyRecipeBook/";
const char* main_menu[]{ "Добавить рецепт", "Найти рецепт", "Удалить рецепт", "Открыть всю книгу" };
enum {add_recipe = 1, find_recipe = 2, pop_recipe = 3, open_book = 4, exit = 0};

int main()
{
	system("chcp 1251>nul");
	std::string path{ path_head };
	path += "dbfiles/recipe_book_db.db";
	SQLiteDBConnection* connection;
	try {
		
		connection = new SQLiteDBConnection(path);
		connection->open();
	}
	catch(int) {
		std::cerr << "Ошибка открытия базы данных" << std::endl;
	}
	RecipesManager* manager = new RecipesManager(connection);
	VisualizerBase* visualizer = new ListVisualizer;
	int res = visualizer->show_menu(main_menu, sizeof(main_menu)/sizeof(main_menu[0]));
	switch (res) {
	case add_recipe:
	
	case find_recipe:

	case pop_recipe:

	case open_book:

	case exit:

	}
	return 0;
}