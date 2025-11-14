#pragma once
#include<iostream>
#include<string>
#include<exception>
using namespace std;

class part
{
protected:
	string id;
	string name;
	string material;
	double diameter;

public:
	part();	// default constructor
	part(const string& i, const string& n, const string& m, const double& d);	// parametrized constructor
	virtual ~part();	// virtual destructor
	virtual string get_id() const = 0;
	virtual string get_name() const = 0;
	virtual string get_material() const = 0;
	virtual double get_diameter() const = 0;
	bool operator=(const string& other) const;	// Operator overloading
	virtual void print_detail() const = 0;	
	bool operator>(const part& other) const;	// Operator overloading
	bool operator<(const part& other) const;	// Operator overloading
};


