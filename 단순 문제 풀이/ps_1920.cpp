#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N,M;
	int tmp;
	cin >> N;
	vector<int> input;

	for(int i=0;i<N;i++){
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());

	cin >> M;
	int l,r,mid;
	int yes;
	for(int i=0;i<M;i++){
		l=0;
		r=N-1;
		yes = 0;
		cin >> tmp;

		while(l<=r){
			mid = (l+r)/2;
			if(input[mid] == tmp){
				yes = 1;
				break;
			}
			else if(input[mid] > tmp)
				r = mid-1;
			else
				l = mid +1;
		}
		if(yes)
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}

	return 0;
}