#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main()
{
	BST<int> s;
	// { Credits: TO GPT FOR TEST CASES
	vector<vector<int>> in = 
	{ 
		{10, 9, 11, 8, 12, 7, 13, 6, 14, 5, 15, 4, 16, 3, 17, 2, 18, 1, 19}, 
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
		{10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
		{8 ,3, 10, 1, 6, 14, 4, 7, 13},
		{5 ,3, 8, 1, 4, 7, 9},
		{50, 30, 70, 20, 40, 60, 80},
		{20, 10, 30, 5, 15, 25, 35},
		{10, 5, 1, 7, 40, 50},
		{15, 6, 3, 7, 2, 4, 13, 9, 18, 17, 20},
		{10, 5, 15, 5, 10, 15},
		{5 ,2, 8, 1, 3, 7, 9},
		{4 ,2, 6, 1, 3, 5, 7},
		{10, 4, 20, 2, 8, 16, 30, 1, 3, 6, 9, 14, 18, 25, 35}
	},
	out = 
	{
		{ 5, 10, 1 },
		{ 5, 10, 1 },
		{ 7, 1, 10 },
		{ 3, 10, 8 },
		{ 5, 3, 8, 1, 4, 7, 9 },
		{ 30, 70, 50 },
		{ 5, 15, 25, 35 },
		{ 5, 40 },
		{ 6, 18, 7, 15 },
		{  },
		{ 5, 2, 8, 1, 3, 7, 9 },
		{ 6, 3, 4 },
		{ 20, 4, 30, 10 },

	};
	// Credits: TO GPT FOR TEST CASES }

	BST<int> bst;

	vector<int> ops;
	ops.reserve(12000);

	int base = 1000000;
	int step = 100;

	for (int i = 0; i < 100000; i++) {
		int A = base + i * step;

		// LR case
		ops.push_back(A);
		ops.push_back(A - 20);
		ops.push_back(A - 10);

		// RL case
		ops.push_back(A + 10);
		ops.push_back(A + 5);
		ops.push_back(A + 7);
	}

	for (int x : ops)
		bst.insert(x);

	// repeatedly erase nodes with two children
	vector<int> del = { 50, 30, 70, 20, 40, 60, 80 };

	//cout << bst << "\n";
	//for (int x : del)
	//	bst.erase(x);

	cout << bst << "\n";

	//while (true)
	//{
	//	int x;
	//	cout << "insert :"; cin >> x;
	//	s.insert(x);
	//	cout << s << "\n";
	//}



	//int st = 0, en = in.size();
	//for (int i = st; i < en; i++)
	//{
	//	cout << "insert: ";
	//	for (auto& in : in[i])
	//		s.insert(in)/*, cout << in << " " */;
	//	cout << '\n' << s << '\n';
	//	cout << "erase: ";
	//	for (auto& out : out[i])
	//		s.erase(out), cout << out << " ";
	//	//cout << s.size() << " " << s.levels() << "\n";
	//	//cout << s.balance(s.root);
	//	cout << '\n' << s << '\n';
	//	s.clear();
	//	cout << "\n";
	//}




	return 0;
}