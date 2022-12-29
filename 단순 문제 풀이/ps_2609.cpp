#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y){
	return y ? gcd(y,x%y) : x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int a,b;
	cin >> a >> b;

	cout << gcd(a,b) << '\n';
	cout << a*b/gcd(a,b);
}