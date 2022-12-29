#include <cstdio>
#include <iostream>

using namespace std;

long long M = 1234567891;

long long mul(int r, int i){
	if(i == 0)
		return 1;
	return r*mul(r,i-1)%M;
}

int main(){
	int L;
	long long result = 0;
	int r=31;
	
	scanf("%d",&L);

	char input[51];

	cin >> input;

	for(int i=0;i<L;i++){
		result += (((int(input[i]) - 96) * mul(r,i)) % M);
		result %= M;
	}
	printf("%lld\n", result);
}