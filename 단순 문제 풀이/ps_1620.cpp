//나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string,int> P;
	vector<string> name;
	string s;
	vector<string> ret;
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> s;
		name.push_back(s);
		P.insert(make_pair(s,i));
	}
	for(int i=0;i<M;i++){
		cin >> s;
		if(s[0] >= 65 && s[0] <= 90){
			ret.push_back(to_string(P[s]));
		}
		else{
			ret.push_back(name[stoi(s)-1]);
		}
	}
	for(int i=0;i<ret.size();i++){
		cout << ret[i] << '\n';
	}
}