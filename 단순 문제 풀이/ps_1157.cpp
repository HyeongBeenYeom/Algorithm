//단어 공부

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int m = -1,tmp,ret;
	bool t = false;
	int a[27]={0,};
	for(int i=0;i<s.size();i++){
		s[i] = toupper(s[i]);
		a[int(s[i])-65]++;
	}
	for(int i=0;i<27;i++){
		tmp = m;
		if(m==a[i])
			t=true;
		m = max(tmp,a[i]);
		if(tmp != m){
			ret = i;
			t = false;
		}
	}
	if(t)
		cout << '?';
	else{
		cout << char(ret+65);
	}
	return 0;
}