//compare 함수

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool compare(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,tmp;
	int ret=0;
	cin >> N;
	vector<pair<int,int>> t;
	for(int i=0;i<N;i++){
		cin >> tmp;
		t.push_back(make_pair(i,tmp));
	}
	sort(t.begin(),t.end(),compare);
	for(int i=0;i<t.size();i++){
		ret += t[i].second * N;
		N--;
	}
	cout << ret << '\n';
}