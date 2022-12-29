//체스판 다시 칠하기

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string Wbox[8]={
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string Bbox[8]={
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
string chess[50];

int W_check(int a, int b){
	int cnt = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(chess[a+i][b+j] != Wbox[i][j]){
				cnt++;
			}
		}
	}

	return cnt;
}

int B_check(int a, int b){
	int cnt = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(chess[a+i][b+j] != Bbox[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main(){
	int N,M;
	int tmp;
	scanf("%d %d", &N, &M);
	int ret = 10000;
	for(int i=0;i<N;i++){
		cin >> chess[i];
	}
	for(int i=0;i+8<=N;i++){
		for(int j=0;j+8<=M;j++){
			int a,b;
			a=W_check(i,j);
			b=B_check(i,j);
			tmp = min(a,b);
			if(tmp<ret){
				ret = tmp;
			}
		}
	}
	printf("%d",ret);
	return 0;
}