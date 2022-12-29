//단어 정렬

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
	if(a.length() == b.length())
		return a<b;
	else
		return a.length() < b.length();
}
int main(){
	int N;
	cin >> N;
	string tmp;
	vector<string> dic;

	for(int i=0;i<N;i++){
		cin >> tmp;
		if(find(dic.begin(), dic.end(), tmp) == dic.end())
			dic.push_back(tmp);
	}

	sort(dic.begin(), dic.end(), compare);

	for(int i=0;i<dic.size();i++){
		cout << dic[i] << '\n';
	}
}