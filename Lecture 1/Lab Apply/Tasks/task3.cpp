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
//int linearSearch(int* arr, int size, int v)
//{
//	while (size && arr[--size] > v);
//	return arr[size] - v ? -1 : size;
//}
//
//int BinarySearch(int* const & arr, int l, int r, const int& v)
//{
//	if (l > r) return -1;
//	int m = l + r >> 1;
//	if (arr[m] == v) return m;
//	return arr[m] > v ? BinarySearch(arr, l, m - 1, v) : BinarySearch(arr, m + 1, r, v);
//}
//
//int BinarySearch(int* const & arr, int l, int r, const int& v, int)
//{
//	while (l <= r)
//	{
//		int m = l + r >> 1;
//		if (arr[m] == v) return m;
//		if (arr[m] > v) r = m - 1;
//		else l = m + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
//	
//	cout << linearSearch(arr, 8, 0) << '\n';
//	cout << linearSearch(arr, 8, 1) << '\n';
//	cout << linearSearch(arr, 8, 2) << '\n';
//	cout << linearSearch(arr, 8, 3) << '\n';
//	cout << linearSearch(arr, 8, 127) << '\n';
//	cout << linearSearch(arr, 8, 128) << '\n';
//	cout << linearSearch(arr, 8, 129) << '\n';
//	cout << "\n\n";
//	cout << BinarySearch(arr, 0, 7, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 1) << '\n';
//	cout << BinarySearch(arr, 0, 7, 2) << '\n';
//	cout << BinarySearch(arr, 0, 7, 3) << '\n';
//	cout << BinarySearch(arr, 0, 7, 127) << '\n';
//	cout << BinarySearch(arr, 0, 7, 128) << '\n';
//	cout << BinarySearch(arr, 0, 7, 129) << '\n';
//	cout << "\n\n";
//	cout << BinarySearch(arr, 0, 7, 0, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 1, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 2, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 3, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 127, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 128, 0) << '\n';
//	cout << BinarySearch(arr, 0, 7, 129, 0) << '\n';
//}