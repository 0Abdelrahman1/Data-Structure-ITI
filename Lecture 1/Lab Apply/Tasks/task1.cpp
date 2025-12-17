//#include <iostream>
//using namespace std;
//
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void bubbleSort(int* arr, int size)
//{
//	int isSortedStart = size;
//	while (size = isSortedStart - 1)
//		for (int i = 0; i < size; i++)
//			if (arr[i] > arr[i + 1])
//				swap(arr[i], arr[i + 1]), isSortedStart = i + 1;
//}
//
//int main()
//{
//	int arr[] = { 3, 2, 1, 4,5,6,7,8 };
//	bubbleSort(arr, sizeof arr / sizeof arr[0]);
//	for (auto x : arr) cout << x << " ";
//}