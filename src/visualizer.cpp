#include "visualizer.h"
#include <windows.h>
#include <iostream>
#include "get_type.h"

int ListVisualizer::show_list(const char* list[], int size)
{
	system("cls");
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << list[i] << std::endl;
	}
	std::cout << "-> ";
	int res = get_int();
	return res;

}