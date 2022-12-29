//약수

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T,tmp;
	vector<int> n;
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> tmp;
		n.push_back(tmp);
	}

	sort(n.begin(),n.end());

	cout << n[0] * n[T-1];
}