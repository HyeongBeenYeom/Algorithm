#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int K, N, tmp;
	vector<int> length;
	length.assign(K,0);
	cin >> K >> N;

	for(int i=0;i<K;i++){
		cin >> tmp;
		length.push_back(tmp);
	}

	sort(length.begin(), length.end());
	unsigned int left = 1, right = length[K-1];
	unsigned int ret = 0, cnt;
	unsigned int mid;

	while(left<=right){
		mid = (left+right)/2;
		cnt = 0;

		for(int i=0;i<K;i++){
			cnt += length[i]/mid;
		}
		if(cnt >= N){
			ret = max(ret,mid);
			left = mid +1;
		}
		else
			right = mid -1;
	}

	cout << ret;
	return 0;
}