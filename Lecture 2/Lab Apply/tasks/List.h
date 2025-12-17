#pragma once
#include<bits/stdc++.h>
#include "Node.h"
template<class T>
class List
{
protected:
	int pSize = 0;
public:
	Node<T>* head = nullptr, * tail = nullptr;
	List() = default;
	List(size_t size, T init = T()) : pSize(size) { while (size--) push_back(init); }
	List(const List<T>& other)
	{
		for (Node<T>* cur = other.head; cur; cur = cur->next) push_back(cur->data, cur->id);
	}
	List<T>& operator=(List<T> other)
	{
		swap(pSize, other.pSize);
		swap(head, other.head);
		swap(tail, other.tail);
		return *this;
	}

	void push_back(T data, int id = -1)
	{
		if (!~id) id = pSize;
		pSize++;
		if (pSize == 1)
			return head = tail = new Node<T>(id, data), void();
		tail = tail->next = new Node<T>(id, data, tail);
	}
	void push_front(T data, int id = -1)
	{
		if (!~id) id = -pSize;
		pSize++;
		if (pSize == 1)
			return head = tail = new Node<T>(id, data), void();
		head = head->prev = new Node<T>(id, data, nullptr, head);
	}


	bool erase(int id = -1)
	{
		Node<T>* ptr = id < 0 ? id == -1 ? tail : head : find(id);
		if (!ptr) return false;
		
		pSize--;

		if (ptr != head && ptr != tail)
			ptr->next->prev = ptr->prev, ptr->prev->next = ptr->next;
		if (ptr == head)
		{
			head = head->next;
			if (head) head->prev = nullptr;
		}
		if (ptr == tail)
		{
			tail = tail->prev;
			if (tail) tail->next = nullptr;
		}
		
		delete ptr;
		return true;
	}

	virtual Node<T>* find(int id) const
	{
		Node<T>* ptr = head;
		while (ptr)
			if (ptr->id == id)
				return ptr;
			else
				ptr = ptr->next;
		return nullptr;
	}

	bool displayNode(int id) const
	{
		Node<T>* ptr = find(id);
		if (!ptr) return false;
		cout << *ptr;
		return true;
	}

	void displayAll() const
	{
		Node<T>* ptr = head;
		while (ptr)
			cout << *ptr << '\n', ptr = ptr->next;
	}

	T& operator[](size_t index) const
	{
		assert(index < pSize);
		Node<T>* ptr = head;
		while (index--)
			ptr = ptr->next;
		return ptr->data;
	}
	size_t size() const { return pSize; }

	~List()
	{
		if (!head) return;
		head = head->next;
		while (head)
			delete head->prev, head = head->next;
		delete tail;
		tail = nullptr;
	}

};