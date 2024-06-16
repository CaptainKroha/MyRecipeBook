#pragma once
#include <string>
#include <list>


class Product {
	std::string name;

public:
	Product(std::string _name):name(_name) { }
};

class ProductWithUnits : public Product {
	int unit_id;
	double qty;

public:
	ProductWithUnits(std::string _name, int u_id, double _qty): Product(_name), unit_id(u_id), qty(_qty) { }
};

class Recipe {
	int id{ -1 };
	std::string name{""};
	std::list<ProductWithUnits> products_list;
	std::string recipe{""};
public:
	Recipe() { }
	Recipe(int _id, std::string _name, std::string _recipe):id(_id), name(_name), recipe(_recipe) { }
};