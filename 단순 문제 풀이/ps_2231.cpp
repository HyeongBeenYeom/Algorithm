#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	int sum,tmp;
	for(int i=1;i<N;i++){
		tmp = i;
		sum = i;

		while(tmp!=0){
			sum += tmp%10;
			tmp /= 10;
		}
		if(sum == N){
			cout << i;
			return 0;
		}
	}
	cout << 0;
	


	return 0;
}