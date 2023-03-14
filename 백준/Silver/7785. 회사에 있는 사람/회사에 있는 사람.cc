#include <bits/stdc++.h>

using namespace std;

map<string, string, greater<string>> m;
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		string a;
		cin >> a;
		cin >> m[a];
	}
	
	for(auto e : m){
		if(e.second == "enter") cout << e.first << '\n';
	}
	return 0;
}