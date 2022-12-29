#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	int sum = 0;
	int human[1001]={0,};
	cout << '<';
	for(int i=1;i<=N;i++){
		human[i] = 1;
	}
	for(int i=0;i<N;i++){
		int tmp = K;
		while(tmp){
			sum++;
			if(sum > N)
				sum %= N;
			if(human[sum]==1)
				tmp--;
		}
		human[sum] = 0;
		cout << sum;
		if(i<N-1)
			cout << ',' << ' ';
	}
	cout << '>';
}