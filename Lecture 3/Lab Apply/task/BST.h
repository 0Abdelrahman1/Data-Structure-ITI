#pragma once
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BST
{
private:
	struct Node
	{
		T data;
		Node *right, *left;
		char lvl;
		Node(const T& data, char lvl = 0, Node* left = nullptr, Node* right = nullptr) : data(data), lvl(lvl), left(left), right(right) {}
		Node(const Node& other) : Node(other.data, other.lvl, other.left ? new Node(*other.left) : 0, other.right ? new Node(*other.right) : 0) {}
		Node& operator=(Node other) { return swap(data, other.data), swap(lvl, other.lvl), swap(left, other.left), swap(right, other.right), * this; }
		Node* clear() { return left = right = nullptr, this; }
		~Node() { delete left; delete right; }
	};

	Node*& rightMost(Node*& cur)
	{
		auto& ret = cur->right ? rightMost(cur->right) : cur;
		return cur->lvl = max(levels(cur->left), levels(cur->right)) + 1, ret;
	}
	bool insert(const T& x, Node*& cur)
	{
		if (!cur) return cur = new Node(x);
		if (cur->data == x) return false;
		bool ret = x < cur->data ? insert(x, cur->left) : insert(x, cur->right);
		return cur->lvl = max(levels(cur->left), levels(cur->right)) + 1, ret;
	}
	bool erase(const T& x, Node*& cur)
	{
		if (!cur) return false;
		char ret = -1;
		if (x < cur->data) ret = erase(x, cur->left);
		else if (x > cur->data) ret = erase(x, cur->right);
		else if (cur->left && cur->right)
		{
			auto& mx = rightMost(cur->left);
			ret = erase(cur->data = mx->data, mx);
		}
		if (~ret) return cur->lvl = max(levels(cur->left), levels(cur->right)) + 1, ret;

		Node* nxt = cur->left ? cur->left : cur->right ? cur->right : 0;
		delete cur->clear();
		if (cur = nxt) cur->lvl = max(levels(cur->left), levels(cur->right)) + 1;
		return true;
	}
	void display(Node*& cur, const string& path = "S", const string& space = "", const string& arrow = "+-->") const
	{
		if (!cur) return;
		string empty = string(arrow.size() - 1, ' ');
		display(cur->right, path + 'R', space + (path.back() == 'L' ? "|" : " ") + empty, arrow);
		if (cur->right) cout << space << (path.back() - 'L' ? " " : "|") << empty << "|\n";
		cout << space << arrow << cur->data << " : " << int(cur->lvl) << '\n';
		if (cur->left) cout << space << (path.back() - 'R' ? " " : "|") << empty << "|\n";
		display(cur->left, path + 'L', space + (path.back() == 'R' ? "|" : " ") + empty, arrow);
	}
	unsigned size(Node*& cur) const { return cur ? size(cur->left) + size(cur->right) + 1 : 0; }
	inline char levels(Node*& cur) const { return cur ? cur->lvl : -1; }

public:
	void balance(Node*& cur, const T& x, const int& change = -1)
	{
		if (!cur) return;
		
		if (x <= cur->data) balance(cur->left, x, change);
		else balance(cur->right, x, change);

		int right = levels(cur->right), left = levels(cur->left);
		if (abs(right - left) <= 1);
		else if (left > right)
		{
			auto nxt = cur->left;
			cur->left = nxt->right;
			nxt->right = cur;
			cur = nxt;
			cur->right->lvl = max(levels(cur->right->left), levels(cur->right->right)) + 1;
		}
		else if (right > left)
		{
			auto nxt = cur->right;
			cur->right = nxt->left;
			nxt->left = cur;
			cur = nxt;
			cur->left->lvl = max(levels(cur->left->left), levels(cur->left->right)) + 1;
		}
		cur->lvl = max(levels(cur->left), levels(cur->right)) + 1;
	}
	BST() = default;
	BST(const BST<T>& other) : root(new Node(*other.root)) {}
	bool insert(const T& x) { auto ret = insert(x, root); if (ret) balance(root, x, +1); return ret; }
	bool erase(const T& x) { auto ret = erase(x, root); if (ret) balance(root, x, -1); return ret; }
	void clear() { delete root; root = nullptr; }
	unsigned size() { return size(root); }
	unsigned height() const { return root->lvl; }
	
	friend ostream& operator<<(ostream& out, BST& bst) { return bst.display(bst.root), out; }
	Node* root = nullptr;
};

