#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	int N,M;
	cin >> N >> M;
	int a,b,ret[101];
	vector<int> v[101];
	bool chk;

	for(int i=0;i<M;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=4;j++){
			chk = 1;
			for(int k=0;k<v[i].size();k++){
				if(ret[v[i][k]] == j)
					chk = 0;
			}
			if(chk){
				ret[i] = j;
				break;
			}
		}
	}
	for(int i=1;i<=N;i++)
		cout << ret[i];
	return 0;
}