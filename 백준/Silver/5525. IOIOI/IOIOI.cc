#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
string s;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string io = "I";
	
	cin >> n >> m >> s;
	
	for(int i=0; i<n; i++){
		io += "OI";
	}
	
	for(int i=0; i<m-(2*n) ; i++){
		if(io == s.substr(i, 2*n+1)) cnt++;
	}
	cout << cnt;
	return 0;
}