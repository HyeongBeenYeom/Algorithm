//two pointer

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	int l_idx,r_idx,v_tmp;
	int c_val[100001];
	int tmp,ret;
	ret = 2000000000;
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> tmp;
		c_val[i] = tmp;
	}

	int l = 0;
	int r = N-1;
	l_idx = l;
	r_idx = r;
	while(l<r){
		v_tmp = c_val[l] + c_val[r];
		if(abs(ret)>abs(v_tmp)){
			ret = v_tmp;
			l_idx = l;
			r_idx = r;
		}
		if(v_tmp < 0)
			l++;
		else if(v_tmp > 0)
			r--;
		else if(v_tmp == 0){
			break;
		}
	}
	cout << c_val[l_idx] << ' ' << c_val[r_idx];
}