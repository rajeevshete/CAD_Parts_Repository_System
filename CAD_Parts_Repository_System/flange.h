#pragma once
#include"part.h"

class flange : public part
{
private:
	double height;

public:
	flange();	// default constructor
	flange(const string& i, const string& n, const string& m, const double& d, const double& h);	// parametrized constructor
	~flange();	// virtual destructor
	string get_id() const;
	string get_name() const;
	string get_material() const;
	double get_diameter() const;
	double get_height() const;
	void print_detail() const;
};