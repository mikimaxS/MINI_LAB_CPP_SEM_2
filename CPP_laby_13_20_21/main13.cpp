#include <iostream>
using namespace std;
#include "student.h"
#include "evaluation.h"



int main()
{
	std::list<int> grades;
	grades.push_back(1);
	grades.push_back(2);
	grades.push_back(7);
	grades.push_back(4);
	grades.push_back(6);
	student mikolaj("mikolaj", "sus", grades);

	cout << mikolaj << "\n\n\n\n";


	cout << "1: datails from file  --------------------------" << endl;

    evaluation e("dane.txt");
	cout << e << endl;

    cout << "2: sorted by surname, name  --------------------" << endl;
	e.sort();
    cout << e << endl;

    cout << "3: marks   -------------------------------------" << endl;
	e.reset_points(2);
    e.set_marks();
    cout << e << endl;

    cout << "4: passing students  ---------------------------" << endl;
    evaluation e2 = e;
    e2.clear_not_passing();
    cout << e2 << endl;

	cout << "5: histogram for points - ALL STUDENTS  --------" << endl;
	map<int, int> m = e.histogram(cout);
	for (auto p : m)
		cout << "(" << p.first << "," << p.second << ")";
	cout << endl << endl;

	cout << "5: histogram for points - PASSING STUDENTS  --------" << endl;
    map<int,int> m2=e2.histogram(cout);
    for (auto p : m2)
	    cout<<"(" << p.first<<","<<p.second<<")";
	cout << endl;
	
    return 0;
}

