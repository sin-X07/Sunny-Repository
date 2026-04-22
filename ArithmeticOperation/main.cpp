#include <iostream>
#include "operation.h"

using namespace std;

int main(){
	double a, b;
	char op;
	double result;

	cout << "Separate with spaces" << endl;
	cin >> a >> op >> b;

	if (op=='+') {
		result = arithmeticOperation::add(a,b);
	} else if (op=='-') {
		result=arithmeticOperation::substract(a,b);
	} else if (op=='*') {
		result=arithmeticOperation::multiply(a,b);
	} else if (op=='/')  {
		result=arithmeticOperation::divide(a,b);
	} 

	cout << "result:" << result << endl;
	
	return 0;
}