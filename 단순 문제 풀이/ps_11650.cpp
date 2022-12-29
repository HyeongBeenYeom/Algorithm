#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct NUM{
	int x,y;
};
bool compare(const NUM &a, const NUM &b){
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
int main(){
	int N;
	cin>>N;

	NUM ret[100001];
	NUM a;
	NUM tmp;
	int idx;
	for(int i=0;i<N;i++){
		scanf("%d %d", &ret[i].x, &ret[i].y);
	}
	
	sort(ret, ret+N,compare);

	for(int i=0;i<N;i++){
		printf("%d %d\n", ret[i].x, ret[i].y);
	}
}