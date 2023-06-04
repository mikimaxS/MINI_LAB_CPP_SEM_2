#pragma once

#include <ostream>
#include <string>
#include <list>
#include <map>

class student
{
public:
    enum class marks { DWA = 2, TRZY, CZTERY, PIEC };

private:
    std::string name, surname;
    std::list<int> points;			//lista punkt�w studenta (wartosci calkowite)
    marks mark = student::marks::DWA;	//lufa (dla uproszczenia tylko wartosci calkowite: 2, 3, 4, 5)
	friend class evaluation;

public:
	//ETAP 1
	student() = default;
    student(const std::string &name, const std::string &surname, const std::list<int> &points);
	friend std::ostream& operator<<(std::ostream& out, const student& st);

	//ETAP 2 - sortowanie (wg surname, name)


	//ETAP 3
    int sum_of_points() const;
	
	//ETAP 5
    void add_to_histogram(std::map<int, int>& m) const;
};



