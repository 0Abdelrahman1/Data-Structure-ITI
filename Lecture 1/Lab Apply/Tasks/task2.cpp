//#include <iostream>
//using namespace std;
//
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void merge(int* arr, int l, int r)
//{
//	int* tmp = new int[r - l + 1], i = l, m = l + r >> 1, j = m + 1, id = 0;
//	while (i <= m && j <= r)
//		if (arr[i] > arr[j])
//			tmp[id++] = arr[j++];
//		else
//			tmp[id++] = arr[i++];
//	while (i <= m)
//		tmp[id++] = arr[i++];
//	while (j <= r)
//		tmp[id++] = arr[j++];
//	for (id = 0, i = l; i <= r; i++)
//		arr[i] = tmp[id++];
//}
//void mergeSort(int* arr, int l, int r)
//{
//	if (l >= r) return;
//	int m = l + r >> 1;
//	mergeSort(arr, l, m);
//	mergeSort(arr, m + 1, r);
//	merge(arr, l, r);
//}
//
//int main()
//{
//	int arr[] = { 3, 2, 4,5,6,1,7,8 };
//	mergeSort(arr, 0, (sizeof arr / sizeof arr[0]) - 1);
//	for (auto x : arr) cout << x << " ";
//	
//}