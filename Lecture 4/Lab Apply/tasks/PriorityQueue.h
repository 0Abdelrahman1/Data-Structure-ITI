#pragma once
#include <bits/stdc++.h>
using namespace std;
template<typename T, class Comp = less<T>, class Container = deque<T>>
class PriorityQueue
{
	Container heap;
	void heapify(size_t top = 1)
	{
		const size_t& left = top << 1;
		const size_t& right = left | 1;
		if (left < heap.size() && Comp()(heap[left], heap[top]))
			top = left;
		if (right < heap.size() && Comp()(heap[right], heap[top]))
			top = right;

		if (top == left >> 1) return;

		swap(heap[top], heap[top >> 1]);
		heapify(top);
	}
public:
	PriorityQueue() = default;
	~PriorityQueue() = default;
	explicit PriorityQueue(Container arr) : heap(arr) { heap.push_front(T()); for (int i = heap.size() - 1 >> 1; i; heapify(i--)); }

	void push(T x)
	{
		heap.push_back(x);
		int cur = heap.size() - 1;
		while (cur >> 1 && Comp()(heap[cur], heap[cur >> 1]))
			swap(heap[cur], heap[cur >> 1]), cur >>= 1;
	}
	T pop()
	{
		T top = heap[1];
		return heap[1] = heap.back(), heap.pop_back(), heapify(), top;
	}
	T top() const { return heap[1]; }
	bool empty() const { return heap.size() <= 1; }
	size_t size() const { return heap.size() - 1; }

	// Weired method !!!
	const T& operator[] (size_t i) const { return assert(i < size()), heap[i + 1]; }

	friend ostream& operator<< (ostream& out, const PriorityQueue<T, Comp, Container>& x) //View()
	{
		for (int i = 1; i < x.heap.size() - 1; i++)
			out << x.heap[i] << " ";
		return out << x.heap.back();
	}
};
