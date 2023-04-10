#include <bits/stdc++.h>

using namespace std;

vector<int> adj[51];
int n, pn, ers;
int answer;

void func(int cur){
	if(cur == ers) return;
	if(adj[cur].empty() || (adj[cur].size() == 1 && adj[cur][0] == ers)) answer++;
	else{
		for(int i=0; i<adj[cur].size(); i++){
			func(adj[cur][i]);
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		int a; 
		cin >> a;
		if(a == -1) pn = i; 
		else adj[a].push_back(i);
	}
	cin >> ers;
	func(pn);
	cout << answer;
	return 0;
}