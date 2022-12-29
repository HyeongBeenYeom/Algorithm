#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	long long T;
	int n,m;
	long long ret=0;
	long long A[1001];
	long long B[1001];
	vector<long long> v_a, v_b;

	cin >> T;

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> A[i];
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> B[i];

	for(int i=0;i<n;i++){
		long long sum = A[i];
		v_a.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum += A[j];
			v_a.push_back(sum);
		}

	}

	for(int i=0;i<m;i++){
		long long sum = B[i];
		v_b.push_back(sum);
		for(int j=i+1;j<m;j++){
			sum += B[j];
			v_b.push_back(sum);
		}
	}

	sort(v_a.begin(), v_a.end());
	sort(v_b.begin(), v_b.end());

	for(int i=0;i<v_a.size();i++){
		int low = lower_bound(v_b.begin(), v_b.end(), T - v_a[i])-v_b.begin();
		int high = upper_bound(v_b.begin(), v_b.end(), T-v_a[i])-v_b.begin();
		ret += high - low;
	}
	cout << ret << '\n';
	return 0;
}