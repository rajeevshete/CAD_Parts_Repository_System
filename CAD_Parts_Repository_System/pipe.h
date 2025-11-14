#pragma once
#include"part.h"

class pipe : public part
{
private:
	double length;

public: 
	pipe();	// default constructor
	pipe(const string& i, const string& n, const string& m, const double& d, double& l);	// parametrized constructor
	~pipe();	// virtual destructor
	string get_id() const;
	string get_name() const;
	string get_material() const;
	double get_diameter() const;
	double get_length() const;
	void print_detail() const;
};
