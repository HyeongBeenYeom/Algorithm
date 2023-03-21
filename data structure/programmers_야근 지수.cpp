#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {    
    long long answer = 0;
    int tmp;
    
    priority_queue<int> pq;
    
    for(int i=0;i<works.size();i++)
        pq.push(works[i]);
    
    while(n-- && !pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(tmp != 1){
            tmp--;
            pq.push(tmp);
        }        
    }
    while(!pq.empty()){
        answer += (pq.top())*(pq.top());
        pq.pop();
    }
    return answer;
}