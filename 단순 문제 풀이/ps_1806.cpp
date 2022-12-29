//부분합

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N,S;
	cin >> N >> S;
	int tmp;
	int idx1 = 0,idx2 = 0, sum = 0;
	int min_len = N + 1;
	int ret[100001];
	for(int i=0;i<N;i++){
		cin >> tmp;
		ret[i] = tmp;
	}
	while(idx1<=idx2){
		if(sum >= S){
			min_len = min(min_len, idx2 - idx1);
			sum -= ret[idx1++];
		}
		else if(idx2 == N)
			break;
		else{
			sum += ret[idx2++];
		}
	}
	if(min_len == N + 1)
		cout << 0;
	else
		cout<< min_len;

	return 0;
}