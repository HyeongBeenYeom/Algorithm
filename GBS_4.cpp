#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;

	long long ret=1,ret2=1;
	long long result = 0;
	int cnt = 0;
	int num;
	int i=0;

	while(i<s.size()){
		num = cnt + 65;
		if(int(s[i]) != num){
			i++;
		}
		else{
			while(cnt < 26){
				num = cnt+65;
				if(int(s[i]) != num)
					break;
				while(int(s[i]) == int(s[i+1])){
					if(int(s[i]) == 90){
						ret++;
					}
					else if(int(s[i]) == 65){
						ret2++;
					}
					i++;
				}
				i++;
				cnt++;
			}
			if(cnt == 26){
				result += ret*ret2;
			}
			cnt = 0;
			ret=1;
			ret2=1;
		}
	}
	cout << result << '\n';
	return 0;
}