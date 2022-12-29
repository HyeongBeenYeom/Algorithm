//제곱 ㄴㄴ 수

#include <cstdio>

using namespace std;


int main(){
	int min, max;
	int square_num[1000001];
	int n =2;
	scanf("%lld %lld", &min, &max);
	int cnt = 0;
	for(int i=min ; i<=max; i++){
		square_num[i] = i;
	}
	while(n*n <= max){
		for(int i=1; i<max;i++){
			if(n*n*i<=max)
				square_num[n*n*i] = 0;
			else
				break;
		}
	}

	for(int i=min; i<=max; i++){
		if(square_num[i] == 0)
			cnt++;
	}

	printf("%d\n", cnt);
	return 0;

}