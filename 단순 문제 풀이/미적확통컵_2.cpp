#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long b,c,a1,a2;

	cin >> b >> c >> a1 >> a2;


	double ret;

	ret += b;
	ret += sqrt(b*b + 4*c);
	cout.precision(10);
	cout << ret/2;
	return 0;
}