//Z

#include <cstdio>
#include <iostream>

using namespace std;

int ret;
int N,r,c;

void find_ret(int y, int x, int t){
	if(x == c && y ==r){
		cout << ret;
		return;
	}
	if(t==1){
		ret++;
		return;
	}
	if(c<x+t && c>=x && r<y+t && r>=y){
		find_ret(y,x,t/2);
		find_ret(y,x+t/2,t/2);
		find_ret(y+t/2,x,t/2);
		find_ret(y+t/2,x+t/2,t/2);
	}
	else
		ret += t*t;
}

int main(){
	
	cin >> N >> r >> c;
	find_ret(0,0,(1<<N));

	return 0;
}