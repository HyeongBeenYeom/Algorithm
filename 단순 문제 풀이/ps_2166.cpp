//precision() : 소수점 원하는 자리까지 출력
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	double ret=0;
	double tmp;
	vector<pair<double,double>> P;
	double x,y;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		P.push_back(make_pair(x,y));
	}
	for(int i=1;i+1<N;i++){
		tmp = (((P[i].first - P[0].first)*(P[i+1].second - P[0].second)) - ((P[i+1].first - P[0].first)*(P[i].second - P[0].second)))/2;
		ret += tmp;
	}
	ret = abs(ret);
	ret *= 10;
	ret = round(ret);
	ret /= 10;
	
	cout << fixed;
	cout.precision(1);
	cout << ret << '\n';
}