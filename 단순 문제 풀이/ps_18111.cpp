#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N,M,B;
	cin >> N >> M >> B;
	int ground[501][501];
	int mintime = 2147483647;
	int maxheight = 0;
	int make,del,height,tmp;


	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> ground[i][j];
		}
	}

	for(int i=0;i<=256;i++){
		make = 0;
		del = 0;
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				height = ground[j][k] - i;
				if(height > 0){
					del += height;
				}
				else
					make -= height;
			}
		}
		if(del + B >= make){
			tmp = del*2 + make;
			if(mintime >= tmp){
				mintime = tmp;
				maxheight = i;
			}
		}
	}
	cout << mintime << ' ' << maxheight;

	return 0;
}