#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin >> T;

	for(int i=0;i<T;i++){
		string VPS;
		cin >> VPS;
		int ret=0;
		for(int j=0;j<VPS.size();j++){
			if(VPS[j]=='(')
				ret++;
			else if(VPS[j]==')')
				ret--;
			if(ret<0){
				ret = -999999;		
				break;
			}
		}
		if(ret == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}