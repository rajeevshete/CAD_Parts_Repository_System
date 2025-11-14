#pragma once
#include<iostream>
#include<exception>
using namespace std;

template<class T>		//Template function
void display(vector<T>& v1)
{
	if (v1.empty())
	{
		throw invalid_argument ("No shapes to print!");
	}
	cout << "List of all parts: " << endl;
	for (auto& p : v1)
	{
		cout << "Id = " << p->get_id() << endl;
		cout << "Name = " << p->get_name() << endl;
		cout << "Material = " << p->get_material() << endl;
		cout << "Diameter = " << p->get_diameter() << endl;
		p->print_detail();
		cout << endl;
	}
};