#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
	return a.first <b.first;
}
int main(){
	int N;

	cin>>N;
	pair<int,string> a;
	vector<pair<int,string>> ret;

	for(int i=0;i<N;i++){
		cin >> a.first >> a.second;
		ret.push_back(a);
	}
	stable_sort(ret.begin(), ret.end(), compare);

	for(int i=0;i<N;i++){
		cout<<ret[i].first << " "<< ret[i].second << '\n';
	}
}