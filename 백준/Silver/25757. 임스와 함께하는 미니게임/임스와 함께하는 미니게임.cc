#include <bits/stdc++.h>

using namespace std;

char c;
int n, p, player;
string s;
unordered_map<string, bool> m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	if (c == 'Y') p = 1;
	else if(c == 'F') p = 2;
	else if(c == 'O') p = 3;
	
	while(n--){
		cin >> s; 
		if(m.find(s) == m.end()){
			player++;
			m[s] = true;
		}
	}
	
	cout << player/p;
	return 0;
}