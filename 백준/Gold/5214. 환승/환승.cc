#include <bits/stdc++.h>

using namespace std;

int n, k, m;
vector<int> ht[100001];
vector<int> t[100001];
bool vis[100001];
int dis[100001];
queue<int> Q;
int main(void){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n >> k >> m;
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=k; j++){
			int a;
			cin >> a;
			ht[i].push_back(a);
			t[a].push_back(i);
		}
	}
	
	Q.push(1);
	dis[1] = 1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int i=0; i<t[cur].size(); i++){
			int cht = t[cur][i];
			if(vis[cht]) continue;
			vis[cht] = true;
			for(int j=0; j<ht[cht].size(); j++){
				if(dis[ht[cht][j]] != 0) continue;
				dis[ht[cht][j]] = dis[cur] + 1;
				Q.push(ht[cht][j]);
			}
		}
	}

	cout << (dis[n] == 0 ? -1 : dis[n]);
	return 0;
}