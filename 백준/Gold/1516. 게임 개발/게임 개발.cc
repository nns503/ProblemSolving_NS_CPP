#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;
int t[501];
int num[501];
vector<int> adj[501];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int sum;
int answer[501];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin	>> t[i];
		int e = 0;
		while(true){
			cin >> e;
			if(e == -1) break;
			num[i]++;
			adj[e].push_back(i);
		}
	}	
	
	for(int i=1; i<=n; i++){
		if(num[i] == 0){
			pq.push({t[i], i});
			answer[i] = t[i];
		}
	}
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		sum = cur.A;
		for(int i=0; i<adj[cur.B].size(); i++){
			int ncur = adj[cur.B][i];
			num[ncur]--;
			if(num[ncur] == 0){
				pq.push({sum + t[ncur], ncur});
				answer[ncur] = sum + t[ncur];
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		cout << answer[i] << '\n';
	}
	
	return 0;
}