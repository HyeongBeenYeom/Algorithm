#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	string a;
	int ret=0;
	cin >> N;
	cin >> a;
	for(int i=0;i<N;i++){
		int t = int(a[i]) - 48;
		ret += t;
	}
	cout << ret;
	return 0;
}