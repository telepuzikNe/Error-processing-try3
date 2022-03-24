#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

double solve_discriminant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

double solve_linear(double b, double c) {
	return -c / b;
}

int solve_equation(double a, double b, double c, vector<double> &solution) {
	if (abs(a) < 0.001) {
		solution.push_back(solve_linear(b, c));
		return -2;
	}

	double discriminant = solve_discriminant(a, b, c);
	if (discriminant <= -0.001)
		return -1;

	double root_1 = (-b + sqrt(discriminant)) / (2 * a),
		   root_2 = (-b - sqrt(discriminant)) / (2 * a);

	if (abs(discriminant) < 0.001) {
		solution.push_back(root_1);
		return -2;
	}

	solution.push_back(root_1);
	solution.push_back(root_2);

	return 1;
}

int main()
{
	vector<double> solution;
	double a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	int rezult = solve_equation(a, b, c, solution);

	if (rezult == 1) {
		cout << "solution: ";
		for (double root : solution) {
			cout << root << "  ";
		}
		cout << endl;
	}
	else if (rezult == -1) {
		cout << "Program terminated with an error\nDiscriminant is less than zero\n";
	}
	else if (rezult == -2) {
		cout << "solution: " << solution[0];
		cout << endl;
	}	
}