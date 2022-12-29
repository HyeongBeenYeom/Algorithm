#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int tmp;
	int a[27];
	for(int i=0;i<27;i++){
		a[i] = -1;
	}
	for(int i=0;i<s.size();i++){
		tmp = int(s[i])-97;
		if(a[tmp] == -1)
			a[tmp] = i;
	}
	for(int i=0;i<26;i++){
		cout << a[i] << ' ';
	}
	return 0;
}