#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int a;
	string s1, s2;
	int minimum = 0, maximum = 11;

	while(1){
		cin >> a;
		if(a==0)
			break;
		cin >> s1 >> s2;
		
		if(s2 == "high" && maximum > a){
			maximum = a;
		}
		else if(s2 == "low" && minimum < a){
			minimum = a;
		}
		else{
			if(a >= maximum || a <= minimum)
				cout << "Stan is dishonest";
			else
				cout << "Stan may be honest";
			maximum = 11;
			minimum = 0;
			cout << '\n';
		}
	}
	return 0;
}