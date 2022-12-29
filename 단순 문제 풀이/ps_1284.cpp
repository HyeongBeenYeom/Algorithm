//집 주소

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	while(true){
		cin >> N;
		int ret = 0;
		int sum = 0;

		if(N == 0)
			break;

		while(true){
			if(N%10==1)
				ret += 2;
			else if(N%10==0)
				ret += 4;
			else
				ret += 3;

			if(N<10)
				break;

			N /= 10;
			sum += 1;
		}
		ret = ret + sum + 2;
		cout << ret << '\n';
	}

	return 0;
}