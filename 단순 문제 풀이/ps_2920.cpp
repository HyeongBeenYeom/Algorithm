#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int a,b,ret = 0;
	bool t = false;
	cin >> a;
	if(a == 1){
		t = true;
	}
	else if(a == 8){
		t = false;
	}
	else{
		cout << "mixed";
		return 0;
	}
	for(int i=1;i<8;i++){
		cin >> b;
		if(t){
			if(b != a + i){
				cout << "mixed";
				return 0;
			}
			else
				ret++;
		}
		else{
			if(b != a-i){
				cout << "mixed";
				return 0;
			}
			else
				ret++;
		}
	}
	if(ret == 7){
		if(t)
			cout << "ascending";
		else
			cout << "descending";
	}

	return 0;
}