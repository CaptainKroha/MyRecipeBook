#pragma once
#include <string>
#include <list>


class Product {
	std::wstring name;

public:
	Product(std::wstring _name):name(_name) { }
};

class ProductWithUnits : public Product {
	int unit_id;
	double qty;

public:
	ProductWithUnits(std::wstring _name, int u_id, double _qty): Product(_name), unit_id(u_id), qty(_qty) { }
};

class Recipe {
	int id{ -1 };
	std::wstring name{L""};
	std::list<ProductWithUnits> products_list;
	std::wstring recipe{L""};
public:
	Recipe() { }
	Recipe(std::wstring _name, std::wstring _recipe) : name(_name), recipe(_recipe) { }
	Recipe(int _id, std::wstring _name, std::wstring _recipe):id(_id), name(_name), recipe(_recipe) { }
};