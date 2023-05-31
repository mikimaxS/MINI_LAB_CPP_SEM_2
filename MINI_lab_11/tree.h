#pragma once
#include <iostream>
#include <list>

class Tree;

class Node
{
	friend Tree;
	int* data;
	Node* leftChild=nullptr;
	Node* rightChild=nullptr;
	Node* parent=nullptr;
public:
	Node(int* data) : data{ data } { }
	int* getData() { return data; }
};

class Tree
{
public:
	Node* root;
	unsigned count;

public:
	Tree() : root{ nullptr }, count{ 0 } { };
	//~Tree() { clear(); };
	bool isEmpty() const { return !root; };
	unsigned size() const { return count; };
	int* getRoot() const;
	bool add(int* data);
	void clear();

	//friend std::ostream& operator << (std::ostream& out, const Tree& tree);

	//std::list<Node*> preorder(Node* n, std::list<Node*> lista) const;

	void removeLeaf(Node* n);
	void removeNode(Node* n);

	//Gotowe - do testów
	void showExampleTree();
	void removeExampleTree();
	Node* getRootNode() { return root; }
};