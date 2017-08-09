#include <iostream>
#include <string>
using namespace std;

double f(double x){
	return cos(x) - x;
}

void fals(double f(double x)){
	double xL, xR, x0, xE;
	int i = 0;
	xL = 0;
	xR = 1;
	xE = xL;
	double err, tol=0.00000001;
	do{
		x0 = (xL*f(xR) - xR*f(xL)) / (f(xR) - f(xL));
		if (f(x0) > 0){
			xL = x0;
		}
		else{
			xR = x0;
		}
		err = fabs((x0 - xE) / x0);
		i++;
		xE = x0;
	} while (err > tol);
	cout.precision(8);
	cout << "Root found at:\t" << x0 << endl;
	cout << "Iterations:\t" << i << endl;
}

void Secant(double f(double x)){
	double x0, x1, x2;
	x0 = 0;
	x1 = 0.1;
	int i=0;
	double err, tol = 0.00000001;
	do{
		x2 = (x0*f(x1) - x1*f(x0)) / (f(x1) - f(x0));
		err = fabs((x2 - x1) / x2);
		i++;
		x0 = x1;
		x1 = x2;
	} while (err > tol);
	cout.precision(8);
	cout << "Root found at:\t" << x2 << endl;
	cout << "Iterations:\t" << i << endl;
}

int main(){
	fals(f);
	//Secant(f);
	system("pause");
	return 7;
}