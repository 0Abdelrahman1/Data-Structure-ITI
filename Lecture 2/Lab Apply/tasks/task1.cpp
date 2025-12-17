//#include <bits/stdc++.h>
//
//#include "List.h"
//#include "SortedList.h"
//#include "Employee.h"
//
//using namespace std;
//
//int main()
//{
//	SortedList<Employee> sl;
//	List<Employee> l;
//
//	Employee a("ahmed", 10, 1000);
//	Employee b("eyad", 20, 2000);
//	Employee c("saad", 30, 3000);
//	Employee d("yassin", 40, 4000);
//
//	l.push_back(c, 3);
//	l.push_back(a, 1);
//	l.push_back(d, 4);
//	l.push_back(b, 2);
//
//	sl.insert(c, 3);
//	sl.insert(a, 1);
//	sl.insert(d, 4);
//	sl.insert(b, 2);
//
//
//	cout << "Test for sl[] & display\n";
//	sl[3] = Employee("abdelrahman", 10, 1);
//	sl.displayNode(4) << '\n';
//	cout << sl[3] << "\n\n";
//
//
//	cout << "Test erase in l:\n";
//	l.displayAll(); cout << "\n\n";
//	cout << "============================ l ==============================\n";
//	l.erase(3);
//	l.displayAll(); cout << "\n\n";
//
//
//	cout << "============================ l ==============================\n";
//	l.erase(1);
//	l.displayAll(); cout << "\n\n";
//
//	cout << "============================ l ==============================\n";
//	l.erase(2);
//	l.displayAll(); cout << "\n\n";
//
//
//	cout << "============================ l ==============================\n";
//	l.erase(4);
//	l.displayAll(); cout << "\n\n";
//
//
//
//
//	cout << "Test erase in sl:\n";
//	sl.displayAll(); cout << "\n\n";
//	cout << "============================ sl ==============================\n";
//	sl.erase(3);
//	sl.displayAll(); cout << "\n\n";
//
//
//	cout << "============================ sl ==============================\n";
//	sl.erase(1);
//	sl.displayAll(); cout << "\n\n";
//
//	cout << "============================ sl ==============================\n";
//	sl.erase(4);
//	sl.displayAll(); cout << "\n\n";
//
//
//	cout << "============================ sl ==============================\n";
//	sl.erase(2);
//	sl.displayAll(); cout << "\n\n";
//
//}