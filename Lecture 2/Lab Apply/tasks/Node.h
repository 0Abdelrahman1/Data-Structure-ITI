#pragma once
#include "Employee.h"
using namespace std;
template<class T>
struct Node
{
	int id = 0;
	T data;
	Node<T>* prev = nullptr, * next = nullptr;
	Node() = default;
	Node(int id, T data, Node<T>* prev = nullptr, Node<T>* next = nullptr) : id(id), data(data), prev(prev), next(next) {}
	Node(const Node<T>& other) : Node(other.id, other.data) {}
	~Node() { prev = next = nullptr; }
	friend ostream& operator<<(ostream& out, const Node<T>& other)
	{
		out << "Node id: " << other.id << '\n';
		out << "Data:\t" << other.data << '\n';
		return out;
	}
};