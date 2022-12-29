#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	int ret=0,cnt=1;
	if(N==1)
		cout << 1;
	while(N!=1){
		if(1+cnt*6>=N){
			cout << cnt+1;
			return 0;
		}
		else{
			N -= cnt*6;
		}
		cnt++;
	}
	return 0;
}