# include <iostream>
# include "dbclass.h"
# include <sqlite3.h>
#include <string>
#include "visualizer.h"
#include <windows.h>
#include "manager.h"
#include <locale>
#include <vector>

const char* path_head = "D:/my_dir_for_learning/projects/MyRecipeBook/";
std::vector<std::wstring> main_menu { L"Добавить рецепт", L"Найти рецепт", L"Удалить рецепт", L"Открыть всю книгу"};
enum {add_recipe = 1, find_recipe = 2, pop_recipe = 3, open_book = 4, out = 0};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::wcin.imbue(std::locale("ru_RU.UTF-8"));
	std::wcout.imbue(std::locale("ru_RU.UTF-8"));
	
	// system("chcp 1251>nul");
	std::string path{ path_head };
	path += "dbfiles/recipe_book_db.db";
	SQLiteDBConnection* connection{ nullptr };
	try {
		connection = new SQLiteDBConnection(path);
		connection->open();
	}
	catch(int) {
		std::cerr << "Ошибка открытия базы данных" << std::endl;
	}

	RecipesManager* manager = new RecipesManager(connection);
	VisualizerBase* visualizer = new ListVisualizer;
	int res = visualizer->show_list(main_menu);
	switch (res) {
	case add_recipe:
		manager->create_recipe();
		break;
	case find_recipe:

	case pop_recipe:

	case open_book:

	case out:
		break;
	}
	return 0;
 }