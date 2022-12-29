#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	long long k,a,b,c,d;

	cin >> k;
	cin >> a >> b >> c >> d;

	long long left,right;

	left = c*k +d;
	right = a*k + b;

	if(left == right)
		cout << "Yes" << ' ' << right;
	else
		cout << "No";

	return 0;
}