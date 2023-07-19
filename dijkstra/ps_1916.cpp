#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int start, dest;
int a,b,c;
int dist[1001];
vector<pair<int,int>> v[100001];
priority_queue<pair<int,int>> pq;

void dijkstra(){
    dist[start] = 0;

    pq.push({dist[start],start});

    while(!pq.empty()){
        int pos = pq.top().second;
        int cost = pq.top().first * -1;
        pq.pop();

        if(dist[pos] < cost)
            continue;

        for(int i=0;i<v[pos].size();i++){
            int next = v[pos][i].first;
            int nextcost = cost + v[pos][i].second;

            if(nextcost < dist[next]){
                dist[next] = nextcost;
                pq.push({nextcost*-1,next});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        dist[i] = 2147483646;

    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    cin >> start >> dest;

    dijkstra();

    cout << dist[dest];
    return 0;
}