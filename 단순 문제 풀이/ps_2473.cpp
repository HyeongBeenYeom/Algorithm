#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int N;
	cin >> N;
	long long ret= 3000000001, tmp;
	int idx1,idx2,idx3;

	vector<long long> v;

	for(int i=0;i<N;i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for(int i=0;i<N-2;i++){
		int l = i+1;
		int r = N-1;
		while(l<r){
			long long sum;
			sum = v[i] + v[l] + v[r];
			if(abs(sum) < ret){
				ret = abs(sum);
				idx1 = i;
				idx2 = l;
				idx3 = r;
			}
			if(sum < 0)
				l++;
			else
				r--;
		}
	}
	cout << v[idx1] << ' ' << v[idx2] << ' ' << v[idx3];
	return 0;
}