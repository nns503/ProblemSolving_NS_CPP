#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[201][201];
bool vis[201];
queue<int> Q;
vector<int> v;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		v.push_back(a);
		if(i == 0){
			Q.push(a);
			vis[a] = true;
		}
	}
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int i=1; i<=n; i++){
			if(vis[i]) continue;
			if(!board[cur][i]) continue;
			Q.push(i);
			vis[i] = true;
		}
	}
	
	for(int i=0; i<m; i++){
		if(!vis[v[i]]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}