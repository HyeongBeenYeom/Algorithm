#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,M;
	cin >> N >> M;
	set<string> l;
	vector<string> ret;
	string tmp;
	for(int i=0;i<N;i++){
		cin >> tmp;
		l.insert(tmp);
	}
	for(int i=0;i<M;i++){
		cin >> tmp;
		if(l.find(tmp) != l.end()){
			ret.push_back(tmp);
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << '\n';
	for(int i=0;i<ret.size();i++){
		cout << ret[i] << '\n';
	}

}