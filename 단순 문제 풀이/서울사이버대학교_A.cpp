#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	int tmp = N;
	string s;
	cin >> s;

	for(int i=0;i<s.size();i++){
		if(s[i] == 's'){
			tmp--;
			i +=7;
		}
		else{
			i+=6;
		}
	}
	int tmp2 = N-tmp;
	if(tmp2 > tmp){
		cout << "security!";
	}
	else if(tmp > tmp2)
		cout << "bigdata?";
	else
		cout << "bigdata?" << ' ' << "security!";
	return 0;
}