#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int a,ret=0;
	for(int i=0;i<5;i++){
		cin >> a;
		ret += (a*a);
	}
	cout << ret %10;
	return 0;
}