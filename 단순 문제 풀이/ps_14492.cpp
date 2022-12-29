#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;

	int A[301][301], B[301][301];

	for(int i=0;i<N;i++){
		for(int j=0; j<N;j++){
			cin >> A[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0; j<N;j++){
			cin >> B[i][j];
		}
	}

	int ret=0;
	int check=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			check = 0;
			for(int k=0;k<N;k++){
				check |= A[i][k] & B[k][j];
				if(check){
					ret++;
					break;
				}
			}
		}
	}
	cout << ret;

	return 0;
}