# include <iostream>
# include "dbclass.h"
# include <sqlite3.h>
# include <string>
# include "visualizer.h"
# include <windows.h>

const char* path_head = "D:/my_dir_for_learning/projects/MyRecipeBook/";
const char* main_menu[]{ "Добавить рецепт", "Найти рецепт", "Удалить рецепт", "Открыть всю книгу" };

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
	VisualizerBase* visualizer = new ListVisualizer;
	int res = visualizer->show_list(main_menu, sizeof(main_menu)/sizeof(main_menu[0]));
	std::cout << res;
	return 0;
}