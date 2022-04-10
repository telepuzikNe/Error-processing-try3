#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace equations_quadratic {

	class NoEquationException : public exception {
	public:
		const char* what() const throw ();
	};

	class AnyRootException : public exception {
	public:
		const char* what() const throw ();
	};

	vector<double> solve_equation(double a, double b, double c);
	// возвращает список корней уравнения a*(x^2) + b*x + c = 0

	double solve_linear(double b, double c);
	// возвращает корень уравнения b*x + c = 0;

	double solve_discriminant(double a, double b, double c);
	// вычисление дискриминанта уравнения a*(x^2) + b*x + c = 0	

	bool equal(double num1, double num2, double epsilon);
	// сравнение двух чисел с заданной точностью
}