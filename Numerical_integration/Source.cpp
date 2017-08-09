#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
	return sin(x);
}

double f1(double x){
	return cos(x);
}

double f3(double x){
	return -cos(x);
}

void trapezoid(double f(double x), double N, double range){
	double h = range / N;
	double x=(f(0)+f(range))/2;
	for (int i = 1; i < N; i++){
		x += f(i*h);
	}
	cout << "trapezd\tI=\t" << x*h << endl;
}

void simpson(double f(double x), double N, double range){
	double h = range / N;
	double x = f(0) + f(range);
	for (int i = 1; i < N; i++){
		if (i % 2 == 1){
			x += 4 * f(i*h);
		}
		else{
			x += 2 * f(i*h);
		}
	}
	cout << "simpson\tI=\t" << x*(h/3) << endl;
}

void boole(double f(double x), double N, double range){
	double h = range / N;
	double x = 7*(f(0) + f(range));
	for (int i = 1; i < N; i++){
		if (i % 2 == 1){
			x += 32 * f(i*h);
		}
		else if(i % 4 == 0){
			x += 14 * f(i*h);
		}
		else {
			x += 12 * f(i*h);
		}
	}
	cout << "boole\tI=\t" << 2*x*h/45 << endl;
}

void euler(double f(double x), double f1(double x), double f3(double x), double N, double range){
	double h = range / N;
	double x = (f(0) + f(range)) / 2;
	for (int i = 1; i < N; i++){
		x += f(i*h);
	}
	x = x*h;
	x += h*h*(f1(0) - f1(range)) / 12 - h*h*h*h*(f3(0) - f3(range)) / 720;
	cout << "euler\tI=\t" << x << endl;
}

void exact(double range){
	cout << "exact=\t" << -cos(range)+cos(0) << endl;
}

int main(){
	cout.precision(13);
	double pi = 3.14159265358979323846;
	for (int n = 4; n <= 1024; n *= 2){
		trapezoid(f, n, pi);
	}
	cout << endl;
	for (int n = 4; n <= 1024; n *= 2){
		simpson(f, n, pi);
	}
	cout << endl;
	for (int n = 4; n <= 1024; n *= 2){
		boole(f, n, pi);
	}
	cout << endl;
	for (int n = 4; n <= 1024; n *= 2){
		euler(f, f1, f3, n, pi);
	}
	cout << endl;
	exact(pi);
	system("pause");
	return 54;
}