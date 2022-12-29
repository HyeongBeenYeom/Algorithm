#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int A,B,V;
	cin >> A >> B >> V;
	int ret = 1;
	ret += (V-A)/(A-B);
	if((V-A)%(A-B) != 0){
		cout << ret + 1;
		return 0;
	}
	if(A >= V)
		cout << 1;
	else
		cout << ret;

	return 0;
}