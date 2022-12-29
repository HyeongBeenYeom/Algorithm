#include <cstdio>
#include <iostream>

using namespace std;


int main(){
	int a,b,ret;
	cin >> a >> b;
	int c = a,d = b;
	int t=0;
	for(int i=0;i<3;i++){
		if(c%10 > d%10){
			t=0;
			break;
		}
		else if(c%10 < d%10){
			t=1;
			break;
		}
		else{
			c/=10;
			d/=10;
		}
	}
	if(t)
		ret = b;
	else
		ret = a;
	for(int i=0;i<3;i++){
		cout << ret%10;
		ret /=10;
	}

}