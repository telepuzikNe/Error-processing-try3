#include "stdafx.h"
#include "solve_equation.h"
using namespace std;

namespace equations_quadratic {

	double solve_discriminant(double a, double b, double c) {
		return b * b - 4 * a * c;
	}

	double solve_linear(double b, double c) {
		return -c / b;
	}

	vector<double> solve_equation(double a, double b, double c) {
		if (abs(a) < 0.001)
			return vector<double>({ solve_linear(b, c) });

		double discriminant = solve_discriminant(a, b, c);
		if (discriminant <= -0.001)
			return vector<double>();
		
		double root_1 = (-b + sqrt(discriminant)) / (2 * a),
			   root_2 = (-b - sqrt(discriminant)) / (2 * a);

		if (abs(discriminant) < 0.001)
			return vector<double>({ root_1 });
		return vector<double>({ root_1, root_2 });
	}
}
