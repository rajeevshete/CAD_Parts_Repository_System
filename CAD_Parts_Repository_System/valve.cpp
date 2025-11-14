#include"valve.h"

valve::valve() {}	// default constructor

valve::valve(const string& i, const string& n, const string& m, const double& d, double& t)	// parametrized constructor
{
	if (d <= 0 || t <= 0)
	{
		throw invalid_argument("Invalid input! Both diameter and thickness should be greater than 0");
	}
	id = i;
	name = n;
	material = m;
	diameter = d;
	thickness = t;
}

valve::~valve() {}	// virtual destructor

string valve::get_id() const
{
	return id;
}

string valve::get_name() const
{
	return name;
}

string valve::get_material() const
{
	return material;
}

double valve::get_diameter() const
{
	return diameter;
}

double valve::get_thickness() const
{
	return thickness;
}

void valve::print_detail() const
{
	cout << "Thickness = " << this->get_thickness() << endl;
}