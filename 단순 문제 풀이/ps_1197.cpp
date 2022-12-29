//MST
//최소 스패닝 트리

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node{
	int start;
	int end;
	int cost;
}N;

int parent[10001];
vector<N> node;

bool compare(const N &a, const N &b){
	return a.cost < b.cost;
}
int find_P(int a){
	if(a == parent[a])
		return a;
	else
		return parent[a] = find_P(parent[a]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int V,E;
	int check,a,b;
	int ret = 0;
	N node_tmp;

	cin >> V >> E;
	for(int i=1;i<=V;i++){
		parent[i] = i;
	}

	for(int i=0;i<E;i++){
		cin >> node_tmp.start >> node_tmp.end >> node_tmp.cost;
		node.push_back(node_tmp);
	}

	sort(node.begin(), node.end(), compare);

	for(int i=0;i<node.size();i++){
		check = 0;
		a = find_P(node[i].start);
		b = find_P(node[i].end);
		if(a == b)
			continue;
		else{
			check = 1;
			parent[a] = b;
		}
		if(check)
			ret += node[i].cost;
	}
	cout << ret << '\n';
}