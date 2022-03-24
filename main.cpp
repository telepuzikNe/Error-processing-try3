#include "stdafx.h"
#include "solve_equation.h"
using namespace std;

int main()
{
	vector<double> solution;
	double a, b, c;

	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;
	
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

	cout << "solution: ";
	for (double root : solution) {
		cout << root << "  ";
	}
	cout << endl;
}
