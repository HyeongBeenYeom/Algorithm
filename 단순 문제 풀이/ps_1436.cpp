//영화감독 숌

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;

	int ret = 666;
	int t = 0;
	bool finish = false;
	string tmp;
	while(1){
		tmp = to_string(ret);
		for(int i = 0;i<tmp.length()-2;i++){
			if(tmp[i] == '6' && tmp[i+1] == '6' && tmp[i+2] == '6'){
				t++;
				if(t == N){
					cout << ret;
					finish = true;
				}
				break;
			}
		}
		ret++;
		if(finish)
			break;
	}
	return 0;
}