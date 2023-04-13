#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int drg[1001];
int n, m;
queue<int> Q;
vector<int> answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int t, a ,b;
		cin >> t >> a;
		t--;
		while(t--){
			cin >> b;
			adj[a].push_back(b);
			a = b; 
			drg[b]++;
		}
	}
	for(int i=1; i<=n; i++){
		if(drg[i] == 0) Q.push(i);
	}	
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		answer.push_back(cur);
		for(int nxt : adj[cur]){
			drg[nxt]--;
			if(drg[nxt] == 0) Q.push(nxt);
		}
	}
	
	if(answer.size() == n){
		for(auto a : answer){
			cout << a << '\n';
		}
	}
	else cout << 0;
	return 0;
}