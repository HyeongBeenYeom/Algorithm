#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const int a, const int b){
	return a<b;
}
int main(){
	int N;
	cin >> N;

	vector<int> v;
	int a;
	for(int i=0;i<N;i++){
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), compare);

	for(int i=0; i<N;i++){
		cout<<v[i]<<'\n';
	}
}