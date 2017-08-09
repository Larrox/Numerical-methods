#include <iostream>
using namespace std;

double f(double x){
	return 1 / (1 + x*x);
}

int main(){
	double xj[11], a[11], b[11], c[11], r[11], pjpp[11], pj[11], beta[11], rho[11];
	double h;
	int n = 11;

	//initial values
	h = 1;
	xj[0] = -5;
	for (int j = 0; j < n; j++){
		if (j>0) xj[j] = xj[j - 1] + h;
		pj[j] = f(xj[j]);
	}

	//initial valuses a,b,c
	a[0] = 0;//not used
	a[1] = 0;
	a[n - 1] = 0;
	for (int j = 2; j < n - 1; j++){
		a[j] = h;
	}

	b[0] = 1;
	b[n - 1] = 1;
	for (int j = 1; j < n - 1; j++){
		b[j] = 4 * h;
	}

	c[0] = 0;
	c[n - 2] = 0;
	c[n - 1] = 0;//not used
	for (int j = 1; j < n - 2; j++){
		c[j] = h;
	}

	r[0] = 0;
	r[n - 1] = 0;
	for (int j = 1; j < n - 1; j++){
		r[j] = (6.0 / h)*(pj[j + 1] - 2 * pj[j] + pj[j - 1]);
	}

	//gausian elimination
	beta[0] = b[0];
	rho[0] = r[0];
	for (int j = 1; j < n; j++){
		beta[j] = b[j] - (a[j] / beta[j - 1])*c[j - 1];
		rho[j] = r[j] - (a[j] / beta[j - 1])*rho[j - 1];
	}

	pjpp[n - 1] = rho[n - 1] / beta[n - 1];
	for (int j = 2; j <= n; j++){
		pjpp[n - j] = (rho[n - j] - c[n - j] * pjpp[n - j + 1]) / beta[n - j];
	}

	//print
	for (int j = 0; j < n; j++){
		cout << pjpp[j] << endl;
	}
	cout << endl;

	//interpolating polynomial
	double p;
	double x = -5;
	double xR = xj[1];
	int j = 0;

	int i = 0;
	cout.precision(6);
	do{
		if (x > xR){
			j++;
			xR = xj[j + 1];
		}

		p = pj[j] + ((pj[j + 1] - pj[j]) / h - h*pjpp[j + 1] / 6 - h*pjpp[j] / 3)*(x - xj[j]) + (pjpp[j] / 2) *(x - xj[j])*(x - xj[j]) + ((pjpp[j + 1] - pjpp[j]) / (6 * h))*(x - xj[j])*(x - xj[j])*(x - xj[j]);
		cout << x << "\t\t" << p << "\t\t" << f(x) << endl;
		x += 0.1;
	} while (x < 5.0);
	system("pause");
	return 0;
}