#include "stdafx.h"
#include "solve_equation.h"
using namespace std;

namespace equations_quadratic {

	const char* NoEquationException::what() const throw () {
		return "Coefficients A and B equal zero\nThe equation loses all meaning\n";
	}

	const char* AnyRootException::what() const throw () {
		return "The root of the quadratic equation belongs to the set from minus infinity to plus infinity";
	}

	double get_discriminant(double a, double b, double c) {
		return b * b - 4 * a * c;
	}

	bool equal(double num1, double num2, double epsilon) {
		if (abs(num1 - num2) <= epsilon)
			return 1;
		return 0;
	}

	double solve_linear(double b, double c) {
		if (equal(b, 0, 0.0001)) {
			if (equal(c, 0, 0.0001))
				throw AnyRootException();
			throw NoEquationException();
		}
		return -c / b;
	}

	vector<double> solve_equation(double a, double b, double c) {
		if (equal(a,0,0.0001))
			return vector<double>({ solve_linear(b, c) });

		double discriminant = get_discriminant(a, b, c);
		if (discriminant <= -0.0001)
			return vector<double>();
		
		double root_1 = (-b + sqrt(discriminant)) / (2 * a),
			   root_2 = (-b - sqrt(discriminant)) / (2 * a);

		if (equal(discriminant, 0, 0.0001))
			return vector<double>({ root_1 });
		return vector<double>({ root_1, root_2 });
	}
}
