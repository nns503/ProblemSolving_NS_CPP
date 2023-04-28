#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int T;
int n, x, y;
bool c[101];

int getDist(pair<int, int> p1, pair<int, int> p2){
	return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		
		cin >> n;
		
		fill(c, c+n+1, false);
		vector<pair<int, int>> p;
		queue<pair<int, int>> Q;
		
		cin >> x >> y;
		Q.push({x, y});
		
		for(int i=0; i<n+1; i++){
			cin >> x >> y;
			p.push_back({x, y});	
		}
		
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			for(int i=0; i<p.size(); i++){
				if(c[i]) continue;
				if(getDist(cur, p[i]) > 1000) continue;
				Q.push(p[i]);
				c[i] = true; 
			}
		}
		
		if(c[n]) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}