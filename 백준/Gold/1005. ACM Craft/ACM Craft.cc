#include<bits/stdc++.h>
#define A first
#define B second

using namespace std;

int T;
int n, k, w;
int d[100001];
int num[100001];
int answer[100001];
vector<int> adj[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		cin >> n >> k;
		
		for(int i=1; i<=n; i++){
			answer[i] = -1;
			adj[i].clear();
		}
		
		for(int i=1; i<=n; i++){
			cin >> d[i];
		}
		
		for(int i=1; i<=k; i++){
			int x, y;
			cin >> x >> y;
			num[y]++;
			adj[x].push_back(y);
		}
		
		cin >> w;
		
		for(int i=1; i<=n; i++){
			if(num[i] == 0){
				q.push({d[i], i});
				answer[i] = d[i];
			}
		}
		
		while(!q.empty()){
			auto cur = q.top(); q.pop();
			for(auto nxt : adj[cur.B]){
				num[nxt]--;
				if(num[nxt] == 0){
					answer[nxt] = answer[cur.B] + d[nxt];
					q.push({answer[nxt], nxt});
				}
			}
		}
		
		cout << answer[w] << '\n';
	}	
	return 0;
}