#include <cstdio>
#include <iostream>

using namespace std;

int parent[500001];
int find_parent(int a){
	if(parent[a] == a)
		return a;
	else
		return parent[a] = find_parent(parent[a]);
}

int dis_union(int s, int e){
	s = find_parent(s);
	e = find_parent(e);

	if(s == e)
		return 1;
	else{
		parent[s] = e;
		return 0;
	}

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n,m;
	int start,end;
	int ret=0;
	cin >> n >> m;

	for(int i=0;i<n;i++)
		parent[i] = i;

	for(int i=1;i<=m;i++){
		cin >> start >> end;
		if(dis_union(start, end)){
			ret = i;
			break;
		}
	}
	cout << ret;
}