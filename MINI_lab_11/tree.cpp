#include "tree.h"
#include "exception.h"

//Gotowe metody pomocnicze - do testów
void Tree::showExampleTree()
{
	std::cout << "   " << *root->data << std::endl;
	std::cout << " " << *root->leftChild->data << "   " << *root->rightChild->data << std::endl;
	std::cout << *root->leftChild->leftChild->data << " " << *root->leftChild->rightChild->data << " ";
	std::cout << *root->rightChild->leftChild->data << " " << *root->rightChild->rightChild->data << std::endl;
}

void Tree::removeExampleTree()
{
	if (root != nullptr)
	{
		removeNode(root->leftChild);
		removeNode(root->rightChild);
	}
}

//todo

int* Tree::getRoot() const
{
	if (this->root == nullptr)
	{
		throw "Puste drzewo - brak korzenia";
	}
	else
	{
		return this->root->data;
	}
}

bool Tree::add(int* data)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
		++this->count;
		return true;
	}
	else
	{
		Node* tmp = this->root;

		while (tmp != nullptr)
		{
			if (*tmp->data > *data)
			{
				if (tmp->leftChild == nullptr)
				{
					tmp->leftChild = new Node(data);
					tmp->leftChild->parent = tmp;
					++this->count;
					return true;
				}

				tmp = tmp->leftChild;
			}
			else if (*tmp->data <= *data)
			{
				if (tmp->rightChild == nullptr)
				{
					tmp->rightChild = new Node(data);
					tmp->rightChild->parent = tmp;
					++this->count;
					return true;
				}

				tmp = tmp->rightChild;
			}
		}
	}

	return false;
}

void Tree::removeLeaf(Node* n)
{
	if (n == nullptr)
	{
		throw TreeException("Wezel nie istnieje");
	}

	if (n == this->root)
	{
		this->count = 0;
		delete n;
		this->root = nullptr;
	}
	else
	{
		if (n->leftChild != nullptr || n->rightChild != nullptr)
		{
			//is not a leaf
			throw NotALeafException(n);
		}
		else
		{
			if (n->parent != nullptr && n->parent->leftChild == n)
			{
				n->parent->leftChild = nullptr;
				--this->count;
				delete n;
			}
			else if (n->parent != nullptr)
			{
				//is rightchild
				n->parent->rightChild = nullptr;
				--this->count;
				delete n;
			}
		}
	}
}

void Tree::removeNode(Node* n)
{
	if (n == nullptr)
	{
		throw TreeException("Wezel nie istnieje");
		return;
	}

	if (this->root == n)
	{
		delete n;
		this->root = nullptr;
		--count;
	}
	else
	{
		if (n->leftChild) removeNode(n->leftChild);
		if (n->rightChild) removeNode(n->rightChild);
		removeLeaf(n);

	}
}

void Tree::clear()
{
	try
	{
		removeNode(this->root);
	}
	catch (NotALeafException& e)
	{
		e.info();
	}
	catch (TreeException& e)
	{
		e.info();
	}
	catch (...)
	{
		std::cout << "err unaccounted for";
	}
}

//void Tree::removeNode(Node* n)
//{
//	if (n == nullptr)
//	{
//		throw TreeException("Wezel nie istnieje");
//	}
//
//	if (this->root == nullptr)
//	{
//		return;
//	}
//
//	if (this->root == n)
//	{
//		this->count = 0;
//		delete n;
//		this->root = nullptr;
//	}
//
//	if (n->parent->leftChild == n) {
//		--this->count;
//		n->parent->leftChild = nullptr;
//	}
//	if (n->parent->rightChild == n) {
//		--this->count;
//		n->parent->rightChild = nullptr;
//	}
//
//	removeNode(n->leftChild);
//	removeNode(n->rightChild);
//
//	delete n;
//}