#pragma once
#include <bits/stdc++.h>
#include "List.h"
#include "Employee.h"
using namespace std;
struct Stack : private List<Employee>
{
//private:
//	using List<Employee>::find(int) const override;
//	void push_back(Employee data, int id = -1) = delete;
//	void push_front(Employee data, int id = -1) = delete;
//	bool erase(int id = -1) = delete;
//	bool displayNode(int id) const = delete;
//	void displayAll() const = delete;
//	Employee& operator[](size_t index) = delete;
//public:

	Stack() = default;
	Stack(const Stack& other) : List<Employee>(other) {}
	Stack& operator=(Stack other) { return List<Employee>::operator=(other), *this; }
	~Stack() = default;

	bool empty() const { return !size(); }
	
	void push(Employee x) { push_back(x); }
	Employee pop()
	{
		assert(!empty());
		Employee tmp = top();
		return erase(), tmp;
	}

	size_t size() const { return List<Employee>::size(); }
	Employee top() const { assert(!empty()); return (*this)[size() - 1]; }

	friend ostream& operator<<(ostream& out, Stack s)
	{
		while (!s.empty())
			out << s.pop() << '\n';
		return out;
	}
};