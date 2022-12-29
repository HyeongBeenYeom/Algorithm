#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;

	int ret=100000000;
	int x=0,tmp,cnt;
	while(5*x<=N){
		cnt = x;
		tmp = N;
		tmp -= 5*x;
		if(tmp%3==0){
			cnt += tmp/3;
			ret = min(ret,cnt);
		}
		x++;
	}
	if(ret == 100000000)
		cout << -1;
	else
		cout << ret;
	return 0;
}