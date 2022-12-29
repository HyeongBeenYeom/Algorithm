#include <cstdio>
#include <iostream>

using namespace std;

int N;
int ret[9];
int visit[9];

void permutation(int a){
	if(a == N){
		for(int i=0;i<N;i++){
			cout << ret[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i=0;i<N;i++){
		if(visit[i] != 1){
			visit[i] = 1;
			ret[a] = i+1;
			permutation(a+1);
			visit[i]=0;
		}
	}
}

int main(){
	
	cin >> N;
	permutation(0);
	return 0;
}