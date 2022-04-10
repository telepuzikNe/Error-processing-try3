#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

double get_discriminant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

bool equal(double num1, double num2, double epsilon) {
	if (abs(num1 - num2) <= epsilon)
		return 1;
	return 0;
}

double solve_linear(double b, double c) {
	if (equal(b,0,0.0001)) {
		if (equal(c, 0, 0.0001))
			return -4;
		return -3;
	}
	return -c / b;
}

int solve_equation(double a, double b, double c, vector<double> &solution) {
	if (equal(a, 0, 0.0001)) {
		if (solve_linear(b, c) == -3)
			return -3;
		else if (solve_linear(b, c) == -4)
			return -4;
		solution.push_back(solve_linear(b, c));
		return -2;
	}

	double discriminant = get_discriminant(a, b, c);
	if (discriminant <= -0.001)
		return -1;

	double root_1 = (-b + sqrt(discriminant)) / (2 * a),
		root_2 = (-b - sqrt(discriminant)) / (2 * a);

	if (equal(discriminant, 0, 0.0001)) {
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

	cout << "Enter coeffitiens a, b, c\n";
	while ((!(cin >> a)) || (!(cin >> b)) || (!(cin >> c)))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Wrong input. Enter again." << endl;
		cout << "Enter coeffitiens a, b, c\n";
	}
	
	int rezult = solve_equation(a, b, c, solution);

	if (rezult == 1) {
		cout << "solution: ";
		for (double root : solution) {
			cout << root << "  ";
		}
		cout << endl;
	}
	else if (rezult == -1) {
		cout << "Discriminant is less than zero\nThe equation has no valid solutions\n";
	}
	else if (rezult == -2) {
		cout << "solution: " << solution[0] << endl;
	}
	else if (rezult == -3) {
		cout << "Coefficients A and B equal zero\nThe equation loses all meaning\n";
	}
	else if (rezult == -4) {
		cout << "The root of the quadratic equation belongs to the set from minus infinity to plus infinity\n";
	}
}