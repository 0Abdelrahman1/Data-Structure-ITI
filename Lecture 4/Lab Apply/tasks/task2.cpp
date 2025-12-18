#include <bits/stdc++.h>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> V;
	
	V.push_back(7);
	V.push_back(8);
	cout << "Size : " << V.size() << " Capacity : " << V.capacity() << '\n';
	V.push_back(9);
	V.push_back(10);
	V.pop_back();
	V.push_back(10);
	cout << "Size : " << V.size() << " Capacity : " << V.capacity() << '\n';
	V.push_back(11);
	cout << "Size : " << V.size() << " Capacity : " << V.capacity() << '\n';

	V.shrinkToFit();
	cout << "Size : " << V.size() << " Capacity : " << V.capacity() << '\n';

	V[0] = 6;

	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << "\n";

	return 0;
}