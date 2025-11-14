#include"part.h"

part::part() {}	// default constructor

part::part(const string& i, const string& n, const string& m, const double& d)	// parametrized constructor
{
	id = i;
	name = n;
	material = m;
	diameter = d;
}

part::~part() {}	// virtual destructor

bool part::operator=(const string& other) const	// Operator overloading
{
	bool found = false;
	if (this->id == other)
	{
		found = true;
	}
	return found;
}

bool part::operator>(const part& other) const	// Operator overloading
{
	bool is_greater = false;
	if (this->diameter > other.diameter)
	{
		is_greater = true;
	}
	return is_greater;
}

bool part::operator<(const part& other) const	// Operator overloading
{
	bool is_smaller = false;
	if (this->diameter < other.diameter)
	{
		is_smaller = true;
	}
	return is_smaller;
}

//string part::get_id() const
//{
//	return id;
//}
//
//string part::get_name() const
//{
//	return name;
//}
//
//string part::get_material() const
//{
//	return material;
//}
//
//double part::get_diameter() const
//{
//	return diameter;
//}

