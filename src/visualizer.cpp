#include "visualizer.h"
#include <windows.h>
#include <iostream>
#include "manager.h"

int ListVisualizer::show_list(const char* list[], int size)
{
	system("cls");
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << list[i] << std::endl;
	}
	std::cout << "-> ";
	int res = InputManager::get_int();
	return res;

}

int ListVisualizer::show_list(std::vector<std::string>& list) {
	system("cls");
	for (int i = 0; i < list.size(); i++) {
		std::cout << i + 1 << ". " << list[i] << std::endl;
	}
	std::cout << "-> ";
	int res = InputManager::get_int();
	return res;
}

int ListVisualizer::show_list(std::vector<std::wstring>& list) {
	system("cls");
	for (int i = 0; i < list.size(); i++) {
		std::wcout << i + 1 << L". " << list[i] << std::endl;
	}
	std::wcout << L"-> ";
	int res = InputManager::get_int();
	return res;
}

int ListVisualizer::show_menu(const char* list[], int size)
{
	system("cls");
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << list[i] << std::endl;
	}
	std::cout << "0. Выход" << std::endl;
	std::cout << "-> ";
	int res = InputManager::get_int();
	return res;

}