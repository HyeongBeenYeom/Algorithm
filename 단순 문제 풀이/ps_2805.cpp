#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


long long find_me(long long N, long long M, long long max, vector<long long> vec){
	long long L = 1;
	long long R = max;
	long long mid;
	while(L<=R){
		mid = (L+R)/2;
		long long result = 0;
		for(int i=0;i<N;i++){
			if(vec[i]>mid)
				result += (vec[i]-mid);
		}
		if(result>=M)
			L = mid + 1;
		else{
			R = mid - 1;
		}
	}
	return R;
}

int main(){
	long long N,M;
	long long max = 0;
	vector<long long> wood;
	scanf("%lld %lld", &N, &M);
	for(int i=0; i<N; i++){
    	long long a;
        cin >> a;
        wood.push_back(a);
        if(a>max)
        	max = a;
	}
	long long ans = find_me(N,M,max,wood);
	printf("%lld\n",ans);
	return 0;
}