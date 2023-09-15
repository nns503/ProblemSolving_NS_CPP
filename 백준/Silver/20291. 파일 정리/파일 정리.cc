#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> m;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for(int i=0; i<n; i++){
		string s; cin >> s;
		int p = s.find('.');
		string tx = s.substr(p+1);
		m[tx]++;
	}	
	
	for(auto cur : m){
		cout << cur.first << ' ' << cur.second << '\n';
	}
	return 0;
}