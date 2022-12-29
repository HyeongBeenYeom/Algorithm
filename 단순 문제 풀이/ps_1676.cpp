#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int ret = 0;
	for(int i=5;i<=N;i*=5){
		ret = ret + N/i;
	}
	cout << ret<<'\n';

}