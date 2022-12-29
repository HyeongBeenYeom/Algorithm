#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(const pair<string,string> &a, const pair<string,string> &b){	
	if(a.first == b.first){
		int size = (a.second.size() < b.second.size()) ? b.second.size() : a.second.size();
		for(int i=0;i<size;i++){			
			if(int(a.second[i]) > int(b.second[i])){
				return a.second > b.second;
			}
			else{
				return a.second > b.second;
			}
		}
	}
	else{
		return a.first < b.first;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	vector<pair<string, string>> v;
	string mentor,mentee;

	for(int i=0;i<N;i++){
		cin >> mentor >> mentee;
		v.push_back(make_pair(mentor,mentee));
	}
	sort(v.begin(), v.end(), compare);

	for(int i=0;i<v.size();i++){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}