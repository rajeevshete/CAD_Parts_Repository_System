#include"flange.h"

flange::flange() {}	// default constructor

flange::flange(const string& i, const string& n, const string& m, const double& d, const double& h)	// parametrized constructor
{
	if (d <= 0 || h <= 0)
	{
		throw invalid_argument("Invalid input! Both diameter and height should be greater than 0");
	}
	id = i;
	name = n;
	material = m;
	diameter = d;
	height = h;
}

flange::~flange() {}	// virtual destructor

string flange::get_id() const
{
	return id;
}

string flange::get_name() const
{
	return name;
}

string flange::get_material() const
{
	return material;
}

double flange::get_diameter() const
{
	return diameter;
}

double flange::get_height() const
{
	return height;
}

void flange::print_detail() const
{
	cout << "Height = " << this->get_height() << endl;
}