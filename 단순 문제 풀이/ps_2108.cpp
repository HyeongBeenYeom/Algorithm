#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	int tmp,sum=0;
	int first=0;
	int maxfreq = -500000;
	int mostfreq;
	int freq[8001] = {0,};
	vector<int> v;
	for(int i=0;i<N;i++){
		cin >> tmp;
		sum += tmp;
		freq[tmp+4000]++;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int range = v.back() - v.front();
	int mean = round((float)sum/N);
	int mid = v[v.size()/2];

	for(int i=0;i<8001;i++){
		if(freq[i] == 0)
			continue;
		if(freq[i] == maxfreq){
			if(first){
				mostfreq = i - 4000;
				first = 0;
			}
		}
		if(freq[i] > maxfreq){
			maxfreq = freq[i];
			mostfreq = i-4000;
			first = 1;
		}
	}
	cout << mean << ' ' << mid << ' ' << mostfreq << ' ' << range;
	return 0;
}