#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x){
	return  cos(x) - x;
}

double fprim(double x){
	return  -sin(x) - 1;
}

double P(double x){
	return (6435 * pow(x, 8) - 12012 * pow(x, 6) + 6930 * pow(x, 4) - 1260 * pow(x, 2) + 35) / 128;
}
double Pprim(double x){
	return (6435 * pow(x, 7) * 8 - 12012 * pow(x, 5) * 6 + 6930 * pow(x, 3) * 4 - 1260 * x * 2) / 128;
}

double y(double x){
	return  pow(x,3)-169;
}

double yprim(double x){
	return  3*pow(x,2);
}

void newton(){
	double i, x0, tol, x1;
	cout << "Please enter initial x:\t";
	cin >> x1;
	cout << "Please enter the tolerance:\t";
	cin >> tol;
	i = 0;
	do{
		x0 = x1;
		x1 =x0 - (f(x0) / fprim(x0));
		i++;
	} while (fabs((x1 - x0) / x1) > tol);
	cout << "x_root=\t" << setprecision(8) << x1 << endl;
	cout << "iterations:" << i << endl;
}

void newton2(){
	double i[4], x0[4], tol, x1[4];
	x1[0] = 0.2;
	x1[1] = 0.5;
	x1[2] = 0.8;
	x1[3] = 0.95;
	cout << "Please enter the tolerance:\t";
	cin >> tol;
	for (int j = 0; j < 4; j++){
		i[j] = 0;
		do{
			x0[j] = x1[j];
			x1[j] = x0[j] - (P(x0[j]) / Pprim(x0[j]));
			i[j]++;
		} while (fabs((x1[j] - x0[j]) / x1[j]) > tol);
		cout << "x_root_" << j+1 << "=\t" << setprecision(8) << x1[j] << endl;
		cout << "iterations:" << i[j] << endl;
	}
}

void newton3(){
	double i, x0, tol, x1;
	cout << "Please enter initial x:\t";
	cin >> x1;
	cout << "Please enter the tolerance:\t";
	cin >> tol;
	i = 0;
	do{
		x0 = x1;
		x1 = x0 - (y(x0) / yprim(x0));
		i++;
	} while (fabs((x1 - x0) / x1) > tol);
	cout << "x_root=\t" << setprecision(9) << x1 << endl;
	cout << "iterations:" << i << endl;
}

int main(){
	//newton3();
	system("Pause");
	return 0;
}