#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include "student.h"


class evaluation
{
private:
	std::list<student> students;

	//wspólne kryteria wystawiania oceny (dla uproszcenia tylko ca³kowite: 3, 4, 5)
	static const std::map<int, int, std::greater<int>> levels;

public:
	//ETAP 1
	evaluation() { }
	evaluation(const std::string& file_name);
	friend std::ostream& operator<<(std::ostream& out, const evaluation& e);

	//ETAP 2
	void sort();	//sortowanie wg surname, name (studenta)

	//ETAP 3
	void reset_points(const int& p); 
	void set_marks(); 

	//ETAP 4
	void clear_not_passing();

	//ETAP 5
	std::map<int, int> histogram(std::ostream& out) const;
};

