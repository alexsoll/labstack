#pragma once
#include "stack.h"
#include <string>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

class TCalculator {
	string infix;
	string postfix;
	TStack<char> STC;
	TStack<double> STD;

public:
	TCalculator(string _infix = "") : STC(_infix.size() + 1), STD(_infix.size() + 1) { infix = _infix; };
	~TCalculator() {};
	string getinfix() {
		return infix;
	}
	string getpostfix() {
		return postfix;
	}
	void setinfix(const string str) {
		infix = str;
	}
	bool check();
	void topostfix();
	double calculate();
	int priority(char res);
};
