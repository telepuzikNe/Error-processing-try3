#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	double a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	double discriminant = b * b - 4 * a * c;

	double x1 = (-b + sqrt(discriminant)) / (2 * a),
	       x2 = (-b - sqrt(discriminant)) / (2 * a);

	cout << "x1= " << x1 << endl
         << "x2= " << x2 << endl;
}