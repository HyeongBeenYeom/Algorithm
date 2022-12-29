//1로 만들기

#include <cstdio>
#include <iostream>

using namespace std;

int ret[1000001];
int find_min(int n){
	for(int i=1;i<=n;i++)
		ret[i] = i-1;
	for(int i=2;i<=n;i++){
		if(i%2==0)
			ret[i] = min(ret[i],ret[i/2]);
		if(i%3==0)
			ret[i] = min(ret[i],ret[i/3]);
		ret[i] = min(ret[i],ret[i-1])+1;
	}
	cout << ret[n];

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;

	find_min(N);

	return 0;
}