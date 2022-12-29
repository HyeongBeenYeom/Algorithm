#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;

void CtoJ(string a){
	bool chk = 0;
	for(int i=0;i<a.size();i++){
		if(int(a[i]) == 95){
			chk = 1;
		}
		else if(chk){
			cout << char(a[i]-32);
			chk = 0;
		}
		else
			cout << a[i];
	}
}

void JtoC(string a){
	for(int i=0;i<a.size();i++){
		if(i<a.size()-1){
			if(int(a[i+1]) < 95){
				if(int(a[i]) < 95){
					cout << char(a[i]+32) << '_';
				}
				else
					cout << a[i] << '_';			
			}
			else if(int(a[i]) < 95)
				cout << char(a[i] + 32);
			else
				cout << a[i];
		}
		else
			if(int(a[i]) < 95){
				cout << char(a[i]+32);
			}
			else
				cout << a[i];
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int j=0,c=0;
	cin >> s;

	for(int i=0;i<s.size();i++){
		if(int(s[i]) < 95){
			j++;
		}
		else if(int(s[i]) == 95){
			c++;
			if(i<s.size()-1){
				if(int(s[i+1]) == 95)
					j++;
			}
			if(i==0)
				j++;
			if(i==s.size()-1)
				j++;
		}
	}
	if(j && c){
		cout << "Error!";	
	}
	else if(j){
		if(int(s[0]) < 95)
			cout << "Error!";
		else
			JtoC(s);
	}
	else if(c)
		CtoJ(s);
	else if(j==0 && c==0){
		for(int i=0;i<s.size();i++)
			cout << s[i];
	}

	
	return 0;
}