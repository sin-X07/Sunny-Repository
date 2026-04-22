#include<iostream>
#include"operation.h"
#include<cmath>

using namespace std;

double arithmeticOperation::add(double a, double b) {
	return a+b;
}

double arithmeticOperation::substract(double a, double b) {
	return a-b;
}

double arithmeticOperation::multiply(double a,double b) {
	return a*b;
}

double arithmeticOperation::divide(double a, double b) {
	const double EPSILON=1e-9;
	if (fabs(b)<EPSILON) {
		cout << "wrong" << endl;
		return 0;
	}
	return a/b;
}