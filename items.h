#pragma once
#include <string>


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