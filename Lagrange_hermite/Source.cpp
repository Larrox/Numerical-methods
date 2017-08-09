#include <iostream>
using namespace std;

double f(double x){
	return exp(x);
}

double f_prim(double x){
	return exp(x);
}

void lagr(double f(double x), double points[], double left, double right, double step){
	int steps = (right - left) / step;
	double x = left, p, ljn;
	int n = sizeof(points);
	for (int i = 0; i <= steps; i++){
		p = 0;
		for (int j = 0; j < n; j++){
			ljn = 1;
			for (int k = 0; k < n; k++){
				if (k != j){
					ljn *= (x - points[k]) / (points[j] - points[k]);
				}
			}
			p += ljn*f(points[j]);
		}
		cout << "x=" << x << "\tpx=" << p << endl; 
		x += 0.1;
	}
}

int main(){
	double points[] = { -1, 0.5, 1.5, 2 };
	double points2[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
	lagr(f, points, -5.0, 5.0, 0.1);
	system("pause");
	return 546465;
}