#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	int W,H,N;

	for(int i=0;i<T;i++){
		cin >> H >> W >> N;
		int floor;
		if(N%H == 0)
			floor = H;
		else
			floor = N%H;		
		int num;
		if(N%H == 0)
			num = N/H;
		else
			num = N/H + 1;
		if(num >= 10){
			cout << floor << num << '\n';
		}
		else
			cout << floor << '0' << num << '\n';
	}
}