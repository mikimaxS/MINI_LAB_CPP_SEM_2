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
	removeNode(root->leftChild);
	removeNode(root->rightChild);
}

//todo

int* Tree::getRoot() const
{
	if (this->root)
		return this->root->data;
	else
		throw "Puste drzewo - brak korzenia";
}

bool Tree::add(int* data)
{
	if (data != nullptr)
	{
		Node* N = new Node(data);
		if (!N) return false;

		if (this->root == nullptr)
		{
			this->root = N;
			++this->count;
			return true;
		}
		else
		{
			Node* tmp = this->root;

			while (true)
			{
				if (*data <= *tmp->data)
				{
					if (tmp->leftChild == nullptr)
					{
						tmp->leftChild = N;
						tmp->leftChild->parent = tmp;
						++this->count;
						return true;
					}
					else
					{
						tmp = tmp->leftChild;
					}
				}
				else
				{
					if (tmp->rightChild == nullptr)
					{
						tmp->rightChild = N;
						tmp->rightChild->parent = tmp;
						++this->count;
						return true;
					}
					else
					{
						tmp = tmp->rightChild;
					}
				}
			}
		}
	}
}

void Tree::removeLeaf(Node* n)
{
	if (n == nullptr) throw TreeException("Wezel nie istnieje");

	if (!n->leftChild && !n->rightChild)
	{
		if (n == this->root)	//is a root
		{
			delete n->data;
			delete n;
			this->count = 0;
			this->root = nullptr;
		}
		else if (n->parent->leftChild == n)	//is left child
		{
			n->parent->leftChild = nullptr;
			delete n->data;
			delete n;
			--this->count;
		}
		else	//is right child
		{
			n->parent->rightChild = nullptr;
			delete n->data;
			delete n;
			--this->count;
		}
	}
	else
	{
		throw NotALeafException(n);
	}
}

void Tree::removeNode(Node* n)
{
	if (n == nullptr) throw TreeException("Wezel nie istnieje");

	if (n->leftChild) {
		removeNode(n->leftChild);
		n->leftChild = nullptr;
	}
	if (n->rightChild) {
		removeNode(n->rightChild);
		n->rightChild = nullptr;
	}
	removeLeaf(n);
}

void Tree::clear()
{
	try
	{
		removeNode(this->root);
	}
	catch (const TreeException& e)
	{
		e.info();
	}
	catch (const NotALeafException& e)
	{
		e.info();
	}
	catch (const std::string& e)
	{
		std::cout << e;
	}
	catch (...)
	{
		std::cout << "err unaccounted for";
	}
}
