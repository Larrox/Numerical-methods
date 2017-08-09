#include <iostream>
using namespace std;

double p(double x){
	return 1 / (1 + x*x);
}

double gauss(double matrix[11][11],double *r, int n){
	double *beta = new (nothrow) double [n];
	double *p = new (nothrow) double[n];
	double *x = new (nothrow) double[n];
	beta[0]=matrix[0][0];
	p[0] = r[0];
	for (int i = 1; i < n; i++){
		beta[i] = matrix[i][i] - (matrix[i - 1][i] / beta[i - 1])*matrix[i][i - 1];
		p[i] = r[i] - (matrix[i - 1][i] / beta[i - 1])*p[i - 1];
	}
	x[n-1] = p[n-1]/beta[n-1];
	for (int i = n - 2; i >= 0; i--){
		x[i] = (p[i] - matrix[i][i+1] * x[i + 1]) / beta[i];
	}
	for (int i = 0; i < n; i++){
		cout << "x=" << x[i] << endl;
	}
	delete[] beta,p,x;
	return *x;
}

int main(){
	double x[11] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
	double mirek[11][11];
	double h = 1;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			mirek[i][j] = 0;
		}
	}
	mirek[0][0] = 1;
	mirek[10][10] = 1;
	for (int i = 1; i < 10; i++){
		mirek[i][i] = 4 * h;
		mirek[i][i + 1] = h;
		mirek[i + 1][i] = h;
	}

	double r[11];
	for (int i = 0; i < 11; i++){
		r[i] = 0;
	}
	for (int i = 1; i < 10; i++){
		r[i] = 6 * (p(x[i + 1]) - 2 * p(x[i]) + p(x[i - 1]));
	}
	gauss(mirek, r, 11);
	system("PAUSE");
	return 0;
}
