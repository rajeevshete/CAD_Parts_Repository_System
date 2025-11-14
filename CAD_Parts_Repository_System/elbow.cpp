#include"elbow.h"

elbow::elbow() {}	// default constructor

elbow::elbow(const string& i, const string& n, const string& m, const double& d, double& a)	// parametrized constructor
{
	if (d <= 0 || a <= 0)
	{
		throw invalid_argument("Invalid input! Both diameter and angle should be greater than 0");
	}
	id = i;
	name = n;
	material = m;
	diameter = d;
	angle = a;
}

elbow::~elbow() {}	// virtual destructor

string elbow::get_id() const
{
	return id;
}

string elbow::get_name() const
{
	return name;
}

string elbow::get_material() const
{
	return material;
}

double elbow::get_diameter() const
{
	return diameter;
}

double elbow::get_angle() const
{
	return angle;
}

void elbow::print_detail() const
{
	cout << "Angle = " << this->get_angle() << endl;
}