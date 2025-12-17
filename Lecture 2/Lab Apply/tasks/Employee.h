#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Employee
{
	string name;
	short age;
	double salary;
	Employee(string name = "", short age = 0, double salary = 0.0) : name(name), age(age), salary(salary) {}
	friend ostream& operator<<(ostream& out, const Employee& other)
	{
		out << "{ name: \"" << other.name << "\", ";
		out << "age: " << other.age << ", ";
		out << "salary: " << other.salary << " }";
		return out;
	}
};
