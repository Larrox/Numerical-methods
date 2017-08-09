#include <iostream>
using namespace std;

double f(double x){
	return x* exp(x);
}

double forward1(double x, double h){
	double a = (f(x + h) - f(x)) / h;
	return a;
}
double forward2(double x, double h){
	double a = (f(x) - 2 * f(x + h) + f(x + 2 * h)) / (h*h);
	return a;
}
double central1(double x, double h){
	double a = (f(x + h) - f(x - h)) / (2 * h);
	return a;
}
double central2(double x, double h){
	double a = (f(x + h) - 2 * f(x) + f(x - h)) / (h*h);
	return a;
}


int main(){
	double x = 2, h = 0.05, E, f1exact, f2exact, X[10], Y[10],n;
	f1exact = (1 + x)*exp(x);
	int i = 0;
	while (h <= 0.5){
		E = abs(f1exact - forward1(x, h));
		X[i] = log(h);
		Y[i] = log(E);
		cout << "h= " << h << " f= " << forward1(x,h) << endl;
		h += 0.05;
		i++;
	}

	double A=0, B=0, C=0, D=0;
	for (i = 0; i < 10; i++){
		A += X[i] * Y[i];
		B += X[i];
		D += Y[i];
		C += X[i] * X[i];
	}
	n = (10 * A - B*D) / (10 * C - B*B);
	cout << "n= " << n << endl;
	system("pause");
	return 0;
}