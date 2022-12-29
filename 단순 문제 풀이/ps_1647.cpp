//도시 분학 계획

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node{
	int start;
	int end;
	int cost;
}Node;

int parent[100001];
vector<Node> node;

bool compare(const Node &a, const Node &b){
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

	int N,M;
	int check,a,b;
	int ret=0;
	int maximum = 0;
	Node tmp;
	cin >> N >> M;

	for(int i=1; i<=N;i++){
		parent[i] = i;
	}

	for(int i=0;i<M;i++){
		cin >> tmp.start >> tmp.end >> tmp.cost;
		node.push_back(tmp);
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
		if(check){
			ret += node[i].cost;
		}
		if(maximum < node[i].cost)
			maximum = node[i].cost;
	}

	cout << ret-maximum;
	return 0;
}