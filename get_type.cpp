#include "get_type.h"
#include <iostream>
#include <string>

int get_int()
{
	std::string tmp;
	std::cin >> tmp;
	if (tmp == "0") return 0;
	return atoi(tmp.c_str());
}