#pragma once
#include <iostream>
#include "tree.h"
#include <string>


class TreeException
{
	std::string err_msg;

public:
	TreeException(std::string s) : err_msg(s) {}

	virtual std::string info() const
	{
		std::cout << err_msg << std::endl;

		return err_msg;
	}
};


class NotALeafException : public TreeException
{
	Node* ptr;

public:
	NotALeafException(Node* p) : ptr(p),
		TreeException("Wezel zawierajacy : " + std::to_string(*p->getData()) + " nie jest lisciem") {}

};