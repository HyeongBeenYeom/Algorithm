#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M,tmp;
	cin >> M;
	string s;
	int num[21] = {0,};

	for(int i=0; i<M;i++){
		cin >> s;
		if(s == "add"){
			cin >> tmp;
			if(num[tmp] == 0)
				num[tmp] = 1;
		}
		else if(s == "remove"){
			cin >> tmp;
			if(num[tmp] == 1)
				num[tmp] = 0;
		}
		else if(s == "check"){
			cin >> tmp;
			if(num[tmp] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(s == "toggle"){
			cin >> tmp;
			if(num[tmp] == 0)
				num[tmp] = 1;
			else
				num[tmp] = 0;
		}
		else if(s == "all"){
			for(int j=0;j<=20;j++)
				num[j] = 1;
		}
		else if(s == "empty"){
			for(int j=0;j<=20;j++)
				num[j] = 0;	
		}
	}
}