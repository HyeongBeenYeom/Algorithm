#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	int num[10001]={0,};
	int tmp;
	for(int i=0;i<N;i++){
		cin >> tmp;
		num[tmp]++;
	}

	for(int i=1;i<10001;i++){
		while(num[i]--)
			cout << i << '\n';
	}

	return 0;
}