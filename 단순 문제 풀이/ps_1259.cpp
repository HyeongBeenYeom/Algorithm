//팰린드롭수

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	string tmp;

	while(1){
		cin >> tmp;
		if(tmp == "0")
			break;
		int r = tmp.size()-1;
		int l=0;
		while(l<r){
			if(tmp[l] == tmp[r]){
				l++;
				r--;
			}
			else{
				cout << "no" << '\n';
				break;
			}
		}
		if(l>=r)
			cout << "yes" << '\n';
	}
}