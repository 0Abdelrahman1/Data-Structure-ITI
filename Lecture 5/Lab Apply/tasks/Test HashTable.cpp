#include <bits/stdc++.h>
#include "HashTable.h"

using namespace std;

// Ai used to validate the correcteness of the class and also to gen test
int main()
{
    HashTable<int, std::string> ht;

    ht.insert(1, "one");
    ht.insert(2, "two");
    ht.insert(3, "three");

    cout << ht.Contains(2) << "\n";   // 1
    cout << ht.Contains(5) << "\n";   // 0

    ht[4] = "four";
    cout << ht[4] << "\n";             // four

    ht.erase(2);
    cout << ht.Contains(2) << "\n";   // 0

    for (int i = 0; i < 1000; i++)
        ht.insert(i, std::to_string(i));

    cout << "Stress test passed\n";
}