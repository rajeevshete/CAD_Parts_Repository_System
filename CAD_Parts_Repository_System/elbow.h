#pragma once
#include"part.h"

class elbow : public part
{
private:
	double angle;

public:
	elbow();	// default constructor
	elbow(const string& i, const string& n, const string& m, const double& d, double& a);	// parametrized constructor
	~elbow();	// virtual destructor
	string get_id() const;
	string get_name() const;
	string get_material() const;
	double get_diameter() const;
	double get_angle() const;
	void print_detail() const;
};