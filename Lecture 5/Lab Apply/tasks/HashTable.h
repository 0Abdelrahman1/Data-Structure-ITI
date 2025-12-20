#pragma once
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

template<class KeyTy, class Ty>
struct HashTable
{
	HashTable(size_t size = 17) : mBuckets(size) {}
	~HashTable() = default;

	bool Contains(KeyTy key) const
	{
		auto& bucket = mBuckets[hasher(key)];
		for (const auto& [k, v] : bucket)
			if (k == key)
				return true;
		return false;
	}

	bool insert(const KeyTy& key, const Ty& value)
	{
		if (Contains(key)) return false;
		if (1.0 * mSize / mBuckets.size() > 0.7) rehash();
		
		mBuckets[hasher(key)].push_back(pair{key, value});
		mSize++;
		return true;
	}

	bool erase(const KeyTy& key)
	{
		auto& bucket = mBuckets[hasher(key)];
		for (auto it = bucket.begin(); it != bucket.end(); ++it)
			if (it->first == key)
				return bucket.erase(it), true;
		return false;
	}

	void clear()
	{
		for (auto& bucket : mBuckets) bucket.clear();
		mSize = 0;
	}

	Ty& operator[](const KeyTy& key) // LookUp
	{
		auto& bucket = mBuckets[hasher(key)];
		for (auto it = bucket.begin(); it != bucket.end(); ++it)
			if (it->first == key)
				return it->second;
		bucket.push_back(pair{key, Ty()});
		mSize++;
		return bucket.back().second;
	}

private:
	size_t mSize = 0;
	vector<list<pair<const KeyTy, Ty>>> mBuckets;

	size_t hasher(const KeyTy& key) const { return hash<KeyTy>()(key) % mBuckets.size(); }
	void rehash()
	{
		vector<size_t> sizes; sizes.reserve(mBuckets.size());
		for (auto& bucket : mBuckets)
			sizes.push_back(bucket.size());
		mBuckets.push_back({});
		mBuckets.resize(mBuckets.capacity());

		for (int i = 0; i < sizes.size(); i++)
			for (auto& bucket = mBuckets[i]; sizes[i]--;)
				mBuckets[hasher(bucket.front().first)].push_back(bucket.front()), bucket.pop_front();
	}
};