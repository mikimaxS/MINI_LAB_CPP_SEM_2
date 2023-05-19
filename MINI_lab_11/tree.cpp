#include "tree.h"
#include "exception.h"

//Gotowe metody pomocnicze - do test�w
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
		Node* tmp = n;
		while (tmp->parent != nullptr)
		{
			tmp = tmp->parent;
		}

		if (tmp == this->root)
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
		else
		{
			//is not in this tree
			throw TreeException("not_in_this_tree");
		}
	}
}

//void Tree::removeNode(Node* n)
//{
//	if (n == nullptr)
//	{
//		throw TreeException("Wezel nie istnieje");
//	}
//
//	if (this->root == n)
//	{
//		delete n;
//		this->root = nullptr;
//	}
//	else
//	{
//		Node* tmp = n;
//		while (tmp->parent != nullptr)
//		{
//			tmp = tmp->parent;
//		}
//
//		if (tmp == this->root)
//		{
//			if (n->rightChild != nullptr)
//			{
//				Node* l_child = n->leftChild;
//				Node* r_child = n->rightChild;
//
//				if (n->parent != nullptr)
//				{
//					if (n->parent->leftChild == n)
//					{
//						n->parent->leftChild = nullptr;
//						delete n;
//					}
//					else 
//					{
//						//is rightchild
//						n->parent->rightChild = nullptr;
//						delete n;
//					}
//				}
//
//				removeNode(l_child);
//				removeNode(r_child);
//			}
//			else if (n->leftChild != nullptr)
//			{
//				Node* l_child = n->leftChild;
//
//				if (n->parent != nullptr)
//				{
//					if (n->parent->leftChild == n)
//					{
//						n->parent->leftChild = nullptr;
//						delete n;
//					}
//					else
//					{
//						//is rightchild
//						n->parent->rightChild = nullptr;
//						delete n;
//					}
//				}
//
//				removeNode(l_child);
//			}
//			else
//			{
//				if (n->parent != nullptr)
//				{
//					if (n->parent->leftChild == n)
//					{
//						n->parent->leftChild = nullptr;
//						delete n;
//					}
//					else 
//					{
//						//is rightchild
//						n->parent->rightChild = nullptr;
//						delete n;
//					}
//				}
//
//				return;
//			}
//		}
//		else
//		{
//			//is not in this tree
//			throw TreeException("not_in_this_tree");
//		}
//	}
//}

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

void Tree::removeNode(Node* n)
{
	if (n == nullptr)
	{
		throw TreeException("Wezel nie istnieje");
	}

	if (this->root == nullptr)
	{
		return;
	}

	if (this->root == n)
	{
		this->count = 0;
		delete n;
		this->root = nullptr;
	}

	if (n->parent->leftChild == n) {
		--this->count;
		n->parent->leftChild = nullptr;
	}
	if (n->parent->rightChild == n) {
		--this->count;
		n->parent->rightChild = nullptr;
	}

	removeNode(n->leftChild);
	removeNode(n->rightChild);

	delete n;
}