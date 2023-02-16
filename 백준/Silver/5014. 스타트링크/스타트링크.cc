#include <bits/stdc++.h>

using namespace std;

int vis[10000001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f,s,g;
	int bt[2];
	queue<int> Q;
	
	cin >> f >> s >> g >> bt[0] >> bt[1];
	bt[1] *= -1;
	fill(vis,vis+f+1,-1);
	Q.push(s);
	vis[s] = 0;
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int i=0;i<2;i++){
			int ns = cur + bt[i];
			if(ns<1||ns>f) continue;
			if(vis[ns]!=-1) continue;
			vis[ns] = vis[cur]+1;
			Q.push(ns);
		}
	}
	
	if(vis[g]==-1) cout << "use the stairs";
	else cout << vis[g];
	
	return 0;
}