#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void stoogeSort(int* const & arr, int l, int r)
{
	int t = (r - l + 1) / 3;
	if (r - l < 2)
		return arr[l] > arr[r] ? swap(arr[l], arr[r]) : void();

	stoogeSort(arr, l, r - t);
	stoogeSort(arr, l + t, r);
	stoogeSort(arr, l, r - t);
}

int main()
{
	int arr[] = { 3, 2, 4,5,6,1,7,8 }, size = sizeof arr / sizeof arr[0];
	srand(time(0));
	random_shuffle(arr, arr + size);
	for (auto x : arr) cout << x << " "; cout << "\n";
	stoogeSort(arr, 0, size - 1);
	for (auto x : arr) cout << x << " "; cout << "\n";
}