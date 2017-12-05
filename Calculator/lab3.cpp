#include <iostream>
#include "calculator.h"
using namespace std;
void main() {
	TCalculator C("(2+3)*2");
	double res;
	res = C.calculate();
	cout << res << endl;
}