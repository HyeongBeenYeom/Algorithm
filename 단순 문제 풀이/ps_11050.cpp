#include <cstdio>
#include <iostream>
using namespace std;

int factorial(int k){
	if(k==1)
		return 1;
	int result = 1;
	for(int i=1;i<=k; i++)
		result *= i;
	return result;
}
int main(){

	int N,K;
	scanf("%d %d", &N, &K);

	cout << factorial(N)/(factorial(N-K)*factorial(K));


}