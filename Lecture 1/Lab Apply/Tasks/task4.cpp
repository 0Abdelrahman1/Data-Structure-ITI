//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void quickSort(int* arr, int l, int r)
//{
//	if (l >= r) return;
//	int p = rand() % (r - l + 1) + l, b = l + 1, e = r;
//	swap(arr[p], arr[l]);
//	p = l;
//	while (true)
//	{
//		while (b <= e && (arr[b] < arr[p] || arr[b] == arr[p] && rand() & 1)) b++;
//		while (e >= b && (arr[e] > arr[p] || arr[e] == arr[p] && rand() & 1)) e--;
//		if (b > e) break;
//		swap(arr[b], arr[e]);
//		b++;
//		e--;
//	}
//	swap(arr[p], arr[e]);
//	swap(p, e);
//	quickSort(arr, l, p - 1);
//	quickSort(arr, p + 1, r);
//}
//
//int main()
//{
//	int arr[] = { 3, 2, 4,5,6,1,7,8 }, size = sizeof arr / sizeof arr[0];
//	srand(time(0));
//	random_shuffle(arr, arr + size);
//	for (auto x : arr) cout << x << " "; cout << "\n";
//	quickSort(arr, 0, size - 1);
//	for (auto x : arr) cout << x << " "; cout << "\n";
//}