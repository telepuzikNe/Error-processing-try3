#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

double solve_discriminant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

vector<double> solve_equation(double a, double b, double c) {

	double discriminant = solve_discriminant(a, b, c);

	double root_1 = (-b + sqrt(discriminant)) / (2 * a),
		   root_2 = (-b - sqrt(discriminant)) / (2 * a);

	return vector<double>({ root_1, root_2 });
}

int main()
{
	vector<double> solution;
	double a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	solution = solve_equation(a, b, c);

	cout << "solution: ";
	for (double root : solution) {
		cout << root << "  ";
	}
	cout << endl;
}