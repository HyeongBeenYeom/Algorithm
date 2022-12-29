#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,M;
	scanf("%d",&N);
	int tmp;
	int card[500001];
	for(int i=0; i<N;i++){
		scanf("%d",&card[i]);
	}
	
	sort(card, card+N);
	
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d",&tmp);
		long long up = upper_bound(card, card+N,tmp) - card;
		long long low = lower_bound(card, card+N, tmp) - card;
		printf("%lld ",up-low);
	}
}