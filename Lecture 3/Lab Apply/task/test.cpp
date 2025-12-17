//#include <bits/stdc++.h>
//#include "BST.h"
//using namespace std;
//
//vector<int> sorted_inc(int n) {
//    vector<int> v(n);
//    iota(v.begin(), v.end(), 1);
//    return v;
//}
//
//vector<int> sorted_dec(int n) {
//    vector<int> v = sorted_inc(n);
//    reverse(v.begin(), v.end());
//    return v;
//}
//
//vector<int> alternating(int n) {
//    vector<int> v;
//    int l = 1, r = n;
//    while (l <= r) {
//        v.push_back(l++);
//        if (l <= r) v.push_back(r--);
//    }
//    return v;
//}
//
//vector<int> random_order(int n) {
//    vector<int> v = sorted_inc(n);
//    shuffle(v.begin(), v.end(), mt19937(random_device{}()));
//    return v;
//}
//
//template<typename BST>
//void test_insert(const string& name, vector<int> order) {
//    BST bst;
//
//    for (int x : order)
//        bst.insert(x);
//
//    int n = order.size();
//    int h = bst.height();
//    double lg = log2(n);
//
//    cout << "[INSERT] " << name
//        << " | n=" << n
//        << " height=" << h
//        << " log2(n)=" << lg
//        << " ratio=" << h / lg
//        << "\n";
//}
//
//template<typename BST>
//void test_erase(const string& name, vector<int> insert_order, vector<int> erase_order) {
//    BST bst;
//
//    for (int x : insert_order)
//        bst.insert(x);
//
//    for (int x : erase_order)
//        bst.erase(x);
//
//    int n = erase_order.size();
//    int h = bst.height();
//
//    cout << "[ERASE] " << name
//        << " | remaining height=" << h
//        << "\n";
//}
//
//int main() {
//    const int N = 100000;
//
//    test_insert<BST<int>>("sorted_inc", sorted_inc(N));
//    test_insert<BST<int>>("sorted_dec", sorted_dec(N));
//    test_insert<BST<int>>("alternating", alternating(N));
//    test_insert<BST<int>>("random", random_order(N));
//
//    auto v = random_order(N);
//    test_erase<BST<int>>("erase_sorted", v, sorted_inc(N));
//    test_erase<BST<int>>("erase_reverse", v, sorted_dec(N));
//    test_erase<BST<int>>("erase_random", v, random_order(N));
//}