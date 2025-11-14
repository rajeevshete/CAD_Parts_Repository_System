#include"pipe.h"

pipe::pipe() {}	// default constructor

pipe::pipe(const string& i, const string& n, const string& m, const double& d, double& l)	// parametrized constructor
{
	if (d <= 0 || l <= 0)
	{
		throw invalid_argument("Invalid input! Both diameter and length should be greater than 0");
	}
	id = i;
	name = n;
	material = m;
	diameter = d;
	length = l;
}

pipe::~pipe() {}	// virtual destructor

string pipe::get_id() const
{
	return id;
}

string pipe::get_name() const
{
	return name;
}

string pipe::get_material() const
{
	return material;
}

double pipe::get_diameter() const
{
	return diameter;
}

double pipe::get_length() const
{
	return length;
}

void pipe::print_detail() const
{
	cout << "Length = " << this->get_length() << endl;
}

