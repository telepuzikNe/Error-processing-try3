#include "stdafx.h"
#include "solve_equation.h"
using namespace std;

int main()
{
	vector<double> solution;
	double a, b, c;
	cout << "Enter coefficients a,b,c\n";
	while ((!(cin >> a)) || (!(cin >> b)) || (!(cin >> c)))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Input error. Enter again." << endl;
		cout << "Enter coefficients\n";
	}
	
	try {
		solution = equations_quadratic::solve_equation(a, b, c);
		if (solution.empty()) {
			cout << "Discriminant is less than zero\nThe equation has no valid solutions\n";
			return 0;
		}
	}
	catch (equations_quadratic::NoEquationException e) {
		cerr << e.what() << endl;
		return -1;
	}
	catch (equations_quadratic::AnyRootException e) {
		cerr << e.what() << endl;
		return -1;
	}
	catch (equations_quadratic::OutOfDoubleException e) {
		cerr << e.what() << endl;
		return -1;
	}

	cout << "solution: ";
	for (double root : solution) {
		cout << root << "  ";
	}
	cout << endl;
}
