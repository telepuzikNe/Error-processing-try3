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
	// ���������� ������ ������ ��������� a*(x^2) + b*x + c = 0

	double solve_linear(double b, double c);
	// ���������� ������ ��������� b*x + c = 0;

	double solve_discriminant(double a, double b, double c);
	// ���������� ������������� ��������� a*(x^2) + b*x + c = 0	

	bool equal(double num1, double num2, double epsilon);
	// ��������� ���� ����� � �������� ���������
}