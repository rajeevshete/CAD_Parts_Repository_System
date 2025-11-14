#pragma once
#include"part.h"

class valve : public part
{
private:
	double thickness;

public:
	valve();	// default constructor
	valve(const string& i, const string& n, const string& m, const double& d, double& t);	// parametrized constructor
	~valve();	// virtual destructor
	string get_id() const;
	string get_name() const;
	string get_material() const;
	double get_diameter() const;
	double get_thickness() const;
	void print_detail() const;
};