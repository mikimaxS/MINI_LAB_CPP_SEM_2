#pragma once
#include <iostream>
#include "tree.h"

class TreeException
{
	const std::string what;
public:
	TreeException(const std::string w) : what(w) {}

	const std::string info() const
	{
		std::cout << this->what << std::endl;
		return this->what;
	}
};


class NotALeafException : public TreeException
{
	Node* ptr;
public:
	NotALeafException(Node* n) :ptr(n), TreeException("") {}

	void info() const
	{
		std::cout << "Wezel zawierajacy: " << *this->ptr->getData() << " nie jest lisciem" << std::endl;
	}
};