#include <iostream>
#include "calculator.h"
using namespace std;
void main () {
	TCalculator C("-2 + (2^2 * 4 - 6) / 5");
	//C.setinfix("-2 + (2^2 * 4 - 6) / 5");
	C.topostfix();

	double res;
	res = C.calculate();
	cout << res << endl;
}