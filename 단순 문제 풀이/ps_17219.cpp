#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N,M;
	cin >> N >> M;

	map<string, string> site;
	string url, password;
	for(int i=0;i<N;i++){
		cin >> url >> password;
		site[url] = password;
	}
	for(int i=0;i<M;i++){
		cin >> url;
		cout << site[url] << '\n';
	}

	return 0;
}