#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101];
bool vis[101];

bool DFS(int a, int target){
	fill(vis, vis+101, false);
	stack<int> s;
	s.push(a);
	while(!s.empty()){
		int cur = s.top(); s.pop();
		if(vis[cur] == true) continue;
		if(a != cur) vis[cur] = true;
		for(int i=0; i<n; i++){
			if(vis[i]) continue;
			if(board[cur][i] == 1) {
				if(i == target) return true;
				s.push(i);
			}
		}
	}
	return false;
}

int main(void){
	
	cin >> n;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cin >> board[y][x];
		}
	}	
	
	for(int i=0; i<n; i++) DFS(i, i);
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cout << DFS(y, x) << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}