//단어의 개수

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int ret=0, a=0;
	getline(cin, s);
	if(s[0]==' '){
		a++;
		if(s.size() == a){
			cout << '0';
			return 0;
		}

	}
	for(int i=a;i<s.size();i++){
		if(s[i]==' '){
			if(i!=s.size()-1)
				ret++;
		}
	}
	cout << ret+1;

	return 0;
}