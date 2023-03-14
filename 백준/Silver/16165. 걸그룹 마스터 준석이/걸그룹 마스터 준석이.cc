#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> um;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(n--){
		string gr;
		cin >> gr;
		int cnt;
		cin >> cnt;
		while(cnt--){
			string member;
			cin >> member;
			um[member] = gr; 
		}
	}
	
	while(m--){
		string s;
		int a;
		cin >> s;
		cin >> a;
		if(a==1){
			cout << um[s] << '\n';
		}
		else{
			for(auto c : um){
				if(c.second == s){
					cout << c.first << '\n';
				}
			}
		}
	}
	return 0;
}