#include <bits/stdc++.h>
#include "stack.h"
#include "queue.h"
#include "Employee.h"

using namespace std;


int main()
{
	Stack s;
	s.push(Employee("ahmed", 10, 1000));
	s.push(Employee("eyad", 20, 2000));
	s.push(Employee("saad", 30, 3000));
	s.push(Employee("yassin", 40, 4000));

	cout << s << '\t' << s.size() << "\n\n";

	cout << "pop: " << s.pop() << "\n\n";
	cout << "stack:\n" << s << '\t' << s.size() << "\n\n";
	cout << "pop: " << s.pop() << "\n\n";
	cout << "stack:\n" << s << '\t' << s.size() << "\n\n";
	cout << "pop: " << s.pop() << "\n\n";
	cout << "stack:\n" << s << '\t' << s.size() << "\n\n";
	cout << "pop: " << s.pop() << "\n\n";
	cout << "stack:\n" << s << '\t' << s.size() << "\n\n";

	cout << "================================================================\n";

	Queue q;
	q.push(Employee("ahmed", 10, 1000));
	q.push(Employee("eyad", 20, 2000));
	q.push(Employee("saad", 30, 3000));
	q.push(Employee("yassin", 40, 4000));

	cout << q << '\t' << q.size() << "\n\n";

	cout << "pop: " << q.pop() << "\n\n";
	cout << "queue:\n" << q << '\t' << q.size() << "\n\n";
	cout << "pop: " << q.pop() << "\n\n";
	cout << "queue:\n" << q << '\t' << q.size() << "\n\n";
	cout << "pop: " << q.pop() << "\n\n";
	cout << "queue:\n" << q << '\t' << q.size() << "\n\n";
	cout << "pop: " << q.pop() << "\n\n";
	cout << "queue:\n" << q << '\t' << q.size() << "\n\n";

	return 0;
}