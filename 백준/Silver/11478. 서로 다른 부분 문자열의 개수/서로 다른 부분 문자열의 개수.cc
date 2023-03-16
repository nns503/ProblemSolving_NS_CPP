#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_set<string> ds;
	string s;
	cin >> s;
	for(int n=1; n<=s.size(); n++){
		for(int i=0; i<=s.size()-n; i++){
			string sub = s.substr(i, n);
			ds.insert(sub);
		}
	}
	cout << ds.size();
	return 0;
}