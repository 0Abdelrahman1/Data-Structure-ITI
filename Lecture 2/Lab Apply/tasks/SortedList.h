#pragma once
#include "List.h"
#include "Employee.h"
template<class T>
class SortedList : public List<T>
{
	void push_back(T, int) = delete;
	void push_front(T, int) = delete;
public:
	SortedList() = default;
	SortedList(size_t size) : List(size) {}
	SortedList(const SortedList<T>& other) : List<T>(other) {}
	SortedList<T>& operator=(SortedList<T> other) { return List<T>::operator=(other), *this; }
	~SortedList() = default;

	virtual Node<T>* find(int id) const override
	{
		Node<T>* cur;
		for (cur = this->head; cur && cur->id < id; cur = cur->next);
		return cur && cur->id != id ? nullptr : cur;
	}

	void insert(T data, int id = -1)
	{
		if (!~id) id = this->pSize;
		if (!this->pSize || id >= this->tail->id) return List<T>::push_back(data, id);
		if (id <= this->head->id) return List<T>::push_front(data, id);

		this->pSize++;
		Node<T>* cur;
		for (cur = this->head; cur->id < id; cur = cur->next);
		cur->prev = cur->prev->next = new Node<T>(id, data, cur->prev, cur);
	}
};