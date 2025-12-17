#pragma once
#include <bits/stdc++.h>
#include "List.h"

struct Queue : private List<Employee>
{
	Queue() = default;
	Queue(const Queue& other) : List<Employee>(other) {}
	~Queue() = default;
	Queue& operator=(Queue other) { return List<Employee>::operator=(other), *this; }
	bool empty() const { return !size(); }
	size_t size() const { return List<Employee>::size(); }

	Employee front() const { return assert(!empty()), (*this)[0]; }
	void push(Employee x) { push_back(x); }
	Employee pop()
	{
		assert(!empty());
		Employee tmp = front();
		return erase(-2), tmp;
	}

	friend ostream& operator<<(ostream& out, Queue q)
	{
		while (!q.empty())
			out << q.pop() << " ";
		return out;
	}
};