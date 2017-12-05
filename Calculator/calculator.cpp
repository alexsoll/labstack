#include "calculator.h"
#include <math.h>
using namespace std;

bool TCalculator::check() {
	STC.clear();
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(')
			STC.push('(');
		if(infix[i] == ')') {
			if (STC.isempty()) 
				return false;
			STC.pop();
		}
	}
	if (!STC.isempty())
		return false;
	else
		return true;
}

int TCalculator::priority(char el) {
	switch(el) {
	case '(': return 0;
	//case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void TCalculator::topostfix() {
	if (check()) {
		postfix = "";
		STC.clear();
		string buf = '(' + infix + ')';
		for (int i = 0; i < buf.size(); i++) {
			if (buf[i] == '(') {
				if (buf[i + 1] == '-')
					postfix += '0';
				STC.push(buf[i]);
			}
			if (buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.')
				postfix += buf[i];
			if (buf[i] == ')') {
				char el = STC.pop();
				while (el != '(') {
					postfix += el;
					el = STC.pop();
				}
			}
			if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^') {
				postfix += " ";
				while (priority(buf[i]) <= priority(STC.top()))
					postfix += STC.pop();
				STC.push(buf[i]);
			}
		}
	}
	else
		throw - 3;
}

double TCalculator::calculate() {
	topostfix();
	STD.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double op1,op2,res;
			op2 = STD.pop();
			op1 = STD.pop();
			
			switch(postfix[i]) {
				case '+':
					res = op1 + op2;
					break;
				case '-':
					res = op1 - op2;
					break;
				case '*':
					res = op1 * op2;
					break;
				case '/':
					res = op1 / op2;
					break;
				case '^':
					res = pow(op1,op2);
					break;
			}
			STD.push(res);
		}
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
			char* tmp;
			double res;
			res = strtod(&postfix[i],&tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			STD.push(res);
		}
	}
	double result = STD.pop();	
	if (!STD.isempty())
		throw - 2;
	return result;
}