//피보나치 함수

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T,tmp;
	cin >> T;

	for(int i=0;i<T;i++){
		cin >> tmp;
		int a=1,b=0,c=0;
		for(int j=0;j<=tmp;j++){
			b=a;
			a=c;
			c = a+b;
		}
		cout << b << ' ' << a << '\n';
	}
}