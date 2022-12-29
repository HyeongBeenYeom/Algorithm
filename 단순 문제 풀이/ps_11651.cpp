#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	int x,y;
	vector<pair<int,int>> v;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end(), compare);

	for(int i=0;i<v.size();i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}