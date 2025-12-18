#pragma once
#include <algorithm>
using namespace std;
template<class T>
struct Vector
{
	Vector() : mData(new T[SPARE_CAPACITY]) {}
	~Vector() { delete[] mData; }
	explicit Vector(size_t size, T init = T()) : mCapacity(size + SPARE_CAPACITY), mSize(size), mData(new T[mCapacity]) { fill(mData, mData + size, init); }
	Vector(const Vector<T>& other) : mCapacity(other.mCapacity), mSize(other.mSize), mData(new T[mCapacity]) { copy(other.mData, other.mData + mSize, mData); }
	Vector<T>& operator=(Vector<T> other)
	{
		swap(mCapacity, other.mCapacity);
		swap(mSize, other.mSize);
		swap(mData, other.mData);
		return *this;
	}

	size_t size() const { return mSize; }
	bool empty() const { return !mSize; }
	size_t capacity() const { return mCapacity; }
	const T* data() const { return mData; }
	T& operator[](size_t i) { return assert(i < mSize), mData[i]; }

	void shrinkToFit()
	{
		reallocate(max(mSize, SPARE_CAPACITY));
	}
	void resize(size_t size, T init = T())
	{
		if (size > mCapacity)
		{
			while (mCapacity < size) mCapacity <<= 1;
			reallocate(mCapacity);
		}
		if (size > mSize)
			fill(mData + mSize, mData + size, init);
		mSize = size;
	}
	void push_back(const T& x)
	{
		if (mSize == mCapacity) expand();
		mData[mSize++] = x;
	}
	void pop_back() { eraseAt(mSize - 1); }
	T back() const { return assert(mSize), mData[mSize - 1]; }
	void eraseAt(size_t i)
	{
		assert(i < mSize);
		move(mData + i + 1, mData + mSize, mData + i);
		mSize--;
	}
	void erase(T x)
	{
		for (int i = 0; i < mSize; i++)
			if (mData[i] == x) eraseAt(i--);
	}

private:
	static const size_t SPARE_CAPACITY = 16;
	size_t mCapacity = SPARE_CAPACITY, mSize = 0;
	T* mData;
	void expand()
	{
		reallocate(mCapacity << 1);
	}
	void reallocate(size_t newCapacity)
	{
		mCapacity = newCapacity;
		T* tmp = new T[mCapacity]{};
		copy(mData, mData + mSize, tmp);
		delete[] mData;
		mData = tmp;
	}
};
