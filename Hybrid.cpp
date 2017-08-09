#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double P(double x){
	return (6435 * pow(x, 8) - 12012 * pow(x, 6) + 6930 * pow(x, 4) - 1260 * pow(x, 2) + 35) / 128;
}
double Pprim(double x){
	return (6435 * pow(x, 7) * 8 - 12012 * pow(x, 5) * 6 + 6930 * pow(x, 3) * 4 - 1260 * x * 2) / 128;
}

double f(double x){
	return pow(x, 2) - 2 * x - 2;
}

double fprim(double x){
	return 2 * x - 2;
}
void hybrid(double z(double x), double zprim(double x)){
	double xl, xr, x0, tol;
	int n=0, b=0;
	cout << "Please enter x left:\t";
	cin >> xl;
	cout << "Please enter x right:\t";
	cin >> xr;
	cout << "Please enter the tolerance:\t";
	cin >> tol;
	double lt, rt;
	double x1, xm, err;
	x0 = xl;

	do{ 
		lt = (x0 - xl)*zprim(x0) - z(x0);
		rt = (x0 - xr)*zprim(x0) - z(x0);
		
		if (rt*lt < 0){
			x1 = x0 - (z(x0) / zprim(x0));
			n++;
		}
		else{
			x1 = (xl + xr) / 2;
			b++;
		}

		if (z(xl)*z(x1) > 0){
			xl = x1;
		}
		else{
			xr = x1;
		}

		err = fabs((x1 - x0) / x1);
		x0 = x1;

	} while (err > tol);
	cout << "X root at:" << setprecision(9) << x1 << endl;
	cout << "Bisections:" << b << endl;
	cout << "Newtons:" << n << endl;
}

int main(){
	hybrid(f,fprim);
	system("Pause");
	return 0;
}