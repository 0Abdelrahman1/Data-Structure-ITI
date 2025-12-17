#pragma once
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class AVL
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

	Node*& rightMost(Node*& cur) const
	{
		return cur->right ? rightMost(cur->right) : cur;
	}
	bool insert(const T& x, Node*& cur)
	{
		if (!cur) return cur = new Node(x);
		if (cur->data == x) return false;
		bool ret = x < cur->data ? insert(x, cur->left) : insert(x, cur->right);
		return rebalance(cur), ret;
	}
	bool erase(const T& x, Node*& cur)
	{
		if (!cur) return false;
		int ret = -1;
		if (x < cur->data) ret = erase(x, cur->left);
		else if (x > cur->data) ret = erase(x, cur->right);
		else if (cur->left && cur->right) ret = erase(cur->data = rightMost(cur->left)->data, cur->left);
		if (~ret) return rebalance(cur), ret;

		Node* nxt = cur->left ? cur->left : cur->right ? cur->right : 0;
		return delete cur->clear(), rebalance(cur = nxt), true;
	}
	void display(Node*const& cur, const string& path = "S", const string& space = "", const string& arrow = "+----->") const
	{
		if (!cur) return;
		string empty = string(arrow.size() - 1, ' ');
		display(cur->right, path + 'R', space + (path.back() == 'L' ? "|" : " ") + empty, arrow);
		if (cur->right) cout << space << (path.back() - 'L' ? " " : "|") << empty << "|\n";
		cout << space << arrow << cur->data << " : " << int(cur->lvl) << '\n';
		if (cur->left) cout << space << (path.back() - 'R' ? " " : "|") << empty << "|\n";
		display(cur->left, path + 'L', space + (path.back() == 'R' ? "|" : " ") + empty, arrow);
	}
	void traverse(Node* cur) { if (!cur) return; traverse(cur->left); cout << cur->data << ' '; traverse(cur->right); }
	unsigned size(Node*& cur) const { return cur ? size(cur->left) + size(cur->right) + 1 : 0; }
	inline char height(Node*& cur) const { return cur ? cur->lvl : -1; }
	inline char balanceFactor(Node*& cur) const { return cur ? height(cur->right) - height(cur->left) : 0; }
	inline void rotateRight(Node*& top)
	{
		auto right = top;
		top = top->left;
		right->left = top->right;
		top->right = right;
		right->lvl = max(height(right->left), height(right->right)) + 1;
		top->lvl = max(height(top->left), height(top->right)) + 1;
	}
	inline void rotateLeft(Node*& top)
	{
		auto left = top;
		top = top->right;
		left->right = top->left;
		top->left = left;
		left->lvl = max(height(left->left), height(left->right)) + 1;
		top->lvl = max(height(top->left), height(top->right)) + 1;
	}
	inline void rebalance(Node*& cur)
	{
		if (!cur) return;
		const char& BF = balanceFactor(cur);

		if (BF < -1)
			return balanceFactor(cur->left) < 0 ? rotateRight(cur) : (rotateLeft(cur->left), rotateRight(cur));
		if (BF > 1)
			return balanceFactor(cur->right) > 0 ? rotateLeft(cur) : (rotateRight(cur->right), rotateLeft(cur));
		cur->lvl = max(height(cur->left), height(cur->right)) + 1;
	}
public:
	AVL() = default;
	AVL(const AVL<T>& other) : root(other.root ? new Node(*other.root) : 0) {}
	~AVL() { clear(); }
	bool insert(const T& x) { return insert(x, root); }
	bool erase(const T& x) { return erase(x, root); }
	void clear() { delete root; root = nullptr; }
	unsigned size() { return size(root); }
	int height() { return this->height(root); }
	void traverse() { traverse(root); }
	
	friend ostream& operator<<(ostream& out, const AVL& bst) { return bst.display(bst.root), out; }
	Node* root = nullptr;
};

