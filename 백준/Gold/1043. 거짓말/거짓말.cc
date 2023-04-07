#include <bits/stdc++.h>

using namespace std;

int n, m, answer;
queue<int> Q;
vector<int> pt[51];
vector<int> h[51];
bool vis[51];
bool tr[51];

int main(void){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m;
	int a;
	cin >> a;
	while(a--){
		int b;
		cin >> b;
		Q.push(b);
	}
	for(int i=1; i<=m; i++){
		cin >> a;
		while(a--){
			int b;
			cin >> b;
			pt[i].push_back(b);
			h[b].push_back(i);
		}
	}
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		tr[cur] = true;
		for(int i=0; i<h[cur].size(); i++){
			int party = h[cur][i];
			if(vis[party]) continue;
			vis[party] = true;
			for(int j=0; j<pt[party].size(); j++){
				if(tr[pt[party][j]]) continue;
				tr[pt[party][j]] = true;
				Q.push(pt[party][j]);
			}
		}
	}
	for(int i=1; i<=m; i++){
		if(!vis[i]) answer++;
	}
	
	cout << answer;
	return 0;
}