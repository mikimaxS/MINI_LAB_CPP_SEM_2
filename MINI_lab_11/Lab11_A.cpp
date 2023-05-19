#include <iostream>
#include <string>
#include "tree.h"
#include "exception.h"

using namespace std;

int main()
{
	cout << "--------------------------------ETAP 1--------------------------------" << endl;

	cout << "---Drzewo int-ow---" << endl;
	
	Tree drzewo_0;
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	
	cout << endl << "---Dodanie korzenia---" << endl;
	drzewo_0.add(new int(5));
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Dodanie kolejnych elementow---" << endl;
	drzewo_0.add(new int(3));
	drzewo_0.add(new int(1));
	drzewo_0.add(new int(4));
	drzewo_0.add(new int(9));
	drzewo_0.add(new int(7));
	drzewo_0.add(new int(13));
	cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
	cout << "Przykladowe drzewo:" << endl;
	drzewo_0.showExampleTree();
	
	cout << "--------------------------------ETAP 2--------------------------------" << endl;
	 
	cout << "---Wyjatki---" << endl;
	try 
	{
		throw TreeException("Wyjatek drzewa");
	}
	catch (const TreeException& e)
	{
		e.info();
	}
	try
	{
		throw NotALeafException(drzewo_0.getRootNode());
	}
	catch (const TreeException& e)
	{
		e.info();
	}
	cout << endl << "---Usuniecie liscia---" << endl;
	try
	{
		drzewo_0.removeLeaf(nullptr);
	}
	catch (const TreeException& e)
	{
		e.info();
	}
	try
	{
		//drzewo_0.removeLeaf(drzewo_0.getRootNode());
	}
	catch (const NotALeafException& e)
	{
		e.info();
	}

	cout << endl << "---Usuniecie przykladowego drzewa---" << endl;
	drzewo_0.removeExampleTree();
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Usuniecie korzenia w przykladowym drzewie---" << endl;
	try
	{
		drzewo_0.removeNode(drzewo_0.getRootNode());
	}
	catch (const NotALeafException& e)
	{
		e.info();
	}
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	
	cout << "--------------------------------ETAP 3--------------------------------" << endl;
	/*
	cout << "---Lista---" << endl;
	drzewo_0.add(new int(5));
	drzewo_0.add(new int(3));
	drzewo_0.add(new int(1));
	drzewo_0.add(new int(4));
	drzewo_0.add(new int(9));
	drzewo_0.add(new int(7));
	drzewo_0.add(new int(13));
	drzewo_0.add(new int(8));
	list<Node*> lista;
	lista = drzewo_0.preorder(drzewo_0.getRootNode(), lista);
	cout << drzewo_0 << endl;
	drzewo_0.clear();
	*/
	cout << endl << "--------------------------------ETAP 4--------------------------------" << endl;
	/*
	cout << "---Szablon---" << endl;
	cout << "---Drzewo int-ow---" << endl;
	Tree<int> drzewo_0;
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Dodanie korzenia---" << endl;
	drzewo_0.add(new int(5));
	try
	{
		cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_0.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Dodanie kolejnych elementow---" << endl;
	drzewo_0.add(new int(3));
	drzewo_0.add(new int(1));
	drzewo_0.add(new int(4));
	drzewo_0.add(new int(9));
	drzewo_0.add(new int(7));
	drzewo_0.add(new int(13));
	cout << "Puste? " << (drzewo_0.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Ilosc elementow drzewa: " << drzewo_0.size() << endl;
	cout << "Przykladowe drzewo:" << endl;
	drzewo_0.showExampleTree();

	cout << endl << "---Drzewo stringow---" << endl;
	Tree<string> drzewo_1;
	try
	{
		cout << "Puste? " << (drzewo_1.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_1.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_1.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Dodanie korzenia---" << endl;
	drzewo_1.add(new string("g"));
	try
	{
		cout << "Puste? " << (drzewo_1.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_1.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_1.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Dodanie kolejnych elementow---" << endl;
	drzewo_1.add(new string("c"));
	drzewo_1.add(new string("a"));
	drzewo_1.add(new string("d"));
	drzewo_1.add(new string("k"));
	drzewo_1.add(new string("j"));
	drzewo_1.add(new string("z"));
	cout << "Puste? " << (drzewo_1.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Ilosc elementow drzewa: " << drzewo_1.size() << endl;
	cout << "Przykladowe drzewo:" << endl;
	drzewo_1.showExampleTree();

	cout << endl << "---Wyjatki---" << endl;
	try
	{
		drzewo_1.removeLeaf(nullptr);
	}
	catch (const TreeException& e)
	{
		e.info();
	}
	try
	{
		drzewo_1.removeLeaf(drzewo_1.getRootNode());
	}
	catch (const NotALeafException<string>& e)
	{
		e.info();
	}

	cout << endl << "---Usuniecie przykladowego drzewa---" << endl;
	drzewo_1.removeExampleTree();
	try
	{
		cout << "Puste? " << (drzewo_1.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_1.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_1.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << endl << "---Usuniecie korzenia w przykladowym drzewie---" << endl;
	try
	{
		drzewo_1.removeNode(drzewo_1.getRootNode());
	}
	catch (const NotALeafException<string>& e)
	{
		e.info();
	}
	try
	{
		cout << "Puste? " << (drzewo_1.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Ilosc elementow drzewa: " << drzewo_1.size() << endl;
		cout << "Korzen drzewa: " << *drzewo_1.getRoot() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	cout << endl << "---Lista---" << endl;
	drzewo_1.add(new string("g"));
	drzewo_1.add(new string("c"));
	drzewo_1.add(new string("a"));
	drzewo_1.add(new string("d"));
	drzewo_1.add(new string("k"));
	drzewo_1.add(new string("j"));
	drzewo_1.add(new string("z"));
	list<Node<string>*> lista;
	lista = drzewo_1.preorder(drzewo_1.getRootNode(), lista);
	cout << drzewo_1 << endl;
	*/
	cout << endl << "--------------------------------KONIEC--------------------------------" << endl;
	return 0;
}