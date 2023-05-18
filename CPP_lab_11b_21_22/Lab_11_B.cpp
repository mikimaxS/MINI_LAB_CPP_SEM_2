#include <iostream>
#include <string>
#include "list.h"
#include "predykat.h"

using namespace std;

int main()
{
	cout << "--------------------------------ETAP 1--------------------------------" << endl;
	//Lista int-ów
	cout << "---Lista int-ow---" << endl;
	linkedList<int> lista_0;
	try
	{
		cout << "Pusta? " << (lista_0.isEmpty() ? "Tak" : "Nie") << endl;
		cout << "Elementy listy: " << lista_0 << endl;
		cout << "Ilosc elementow: " << lista_0.size() << endl;
		cout << "Pierwszy element: " << lista_0.getFirst() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	cout << endl;
	lista_0.addFront(3);
	cout << "Pusta? " << (lista_0.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Elementy listy: " << lista_0 << endl;
	cout << "Ilosc elementow: " << lista_0.size() << endl;
	lista_0.addFront(5);
	lista_0.addFront(7);
	lista_0.addFront(9);
	cout << endl;
	cout << "Pusta? " << (lista_0.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Elementy listy: " << lista_0 << endl;
	cout << "Ilosc elementow: " << lista_0.size() << endl;
	try
	{
		cout << "Pierwszy element: " << lista_0.getFirst() << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	//Lista string-ów
	cout << endl;
	cout << "---Lista string-ow---" << endl;
	linkedList<string> lista_1;
	cout << "Pusta? " << (lista_1.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Elementy listy: " << lista_1 << endl;
	cout << "Ilosc elementow: " << lista_1.size() << endl;

	cout << endl;
	lista_1.addFront("Peleusa...");
	cout << "Pusta? " << (lista_1.isEmpty() ? "Tak" : "Nie") << endl;
	cout << "Elementy listy: " << lista_1 << endl;
	cout << "Ilosc elementow: " << lista_1.size() << endl;
	lista_1.addFront("syna");
	lista_1.addFront("Achilla,");
	lista_1.addFront("opiewaj");
	lista_1.addFront("bogini,");
	lista_1.addFront("Gniew,");
	cout << endl;
	cout << "Pusta? " << (lista_1.isEmpty() ? "Tak" : "Nie") << endl;
	cout << lista_1;
	cout << " - Homer, Iliada" << endl;
	cout << "Ilosc elementow: " << lista_1.size() << endl;

	cout << "Usuwamy elementy listy z konca" << endl;
	while (!lista_1.isEmpty())
	{
		lista_1.popBack();
		cout << "Elementy listy: " << lista_1 << endl;
		cout << "Ilosc elementow: " << lista_1.size() << endl;
	}
	lista_1.popBack();

	cout << endl;
	cout << "Dodawanie elementow na koniec: " << endl;
	lista_1.addBack("...zgube");
	lista_1.addBack("niosacy");
	lista_1.addBack("i");
	lista_1.addBack("kleski");
	lista_1.addBack("nieprzeliczone");
	lista_1.addBack("Achajom");
	cout << endl << lista_1 << endl;
	linkedList<string> lista_2(lista_1);
	lista_1.clear();
	cout << endl;
	cout << "Wyczyszczona lista stringow (powinno byc pusto):  ";
	cout << lista_1 << endl;
	cout << "Kopia listy stringow: ";
	cout << lista_2 << endl << endl;

	cout << "--------------------------------ETAP 2--------------------------------" << endl;
	/*
	cout << "---Operacje za pomoca iteratorow---" << endl << endl;
	linkedList<int>::listIterator it_i = lista_0.begin();
	cout << "Pierwszy element listy in-ow: " << *it_i << endl;
	linkedList<string>::listIterator it_s = lista_2.end();
	cout << "Ostatni element listy stringow: " << *it_s << endl;
	cout << "Wyjatki (pusta lista):" << endl;
	try {
		linkedList<string>::listIterator it = lista_1.begin();
		cout << *it << endl;
	}
	catch (std::exception& ex)
	{
		cout << ex.what();
		cout << endl;
	}
	cout << endl;
	linkedList<int>::listIterator it_i2 = lista_0.end();
	cout << "Post-dekrementacja listy in-ow (oststni element): " << *it_i2-- << endl;
	cout << "Pre-dekrementacja listy in-ow (trzeci element od konca): " << *--it_i2 << endl;
	cout << "Wyjatki inkrementacji (koniec listy):" << endl;
	try {
		it_i2--;
		cout << "Poprzedni element listy int-ow: " << *it_i2 << endl;
		it_i2--;
		cout << "Poprzedni element listy int-ow: " << *it_i2 << endl;
	}
	catch (std::exception& ex)
	{
		cout << ex.what();
		cout << endl;
	}
	cout << "Operator == (wers pisany od konca i bez pierwszego wyrazu):" << endl;
	linkedList<string>::listIterator it_s2 = lista_2.end();
	while (!(it_s2 == lista_2.begin()))
	{
		cout << *it_s2 << " ";
		it_s2--;
	}
	cout << endl << endl;
	*/

	cout << "--------------------------------ETAP 3--------------------------------" << endl;
	/*
	cout << "Predykat" << endl;
	int ilosc = 6;
	StringLongerThan pred(ilosc);
	cout << "Wyraz \"malo\" ma wiecej liter niz " << ilosc << " : " << (pred("malo") ? "tak" : "nie") << endl;
	cout << "Wyraz \"duuuuzo\" ma wiecej liter niz " << ilosc << " : " << (pred("duuuuzo") ? "tak" : "nie") << endl;
	linkedList<string> *lista_3;
	StringLongerThan pred1(7);
	lista_3 = lista_2.extract(pred1);
	cout << "Lista wyekstrachowana (wyrazy dluzsze niz 7 liter): ";
	cout << *lista_3 << endl;
	cout << "Sprawdzenie wskaznika prev: ";
	linkedList<string>::listIterator it_s3 = lista_3->end();
	it_s3--;
	cout << "Powinien byc wyraz (zgube): " << *it_s3 << endl;
	*/

	cout << endl;
	cout << "--------------------------------KONIEC--------------------------------" << endl;
	return 0;
}