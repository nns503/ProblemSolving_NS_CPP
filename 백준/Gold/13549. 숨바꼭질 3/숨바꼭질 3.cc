#include <bits/stdc++.h>

using namespace std;

int n,k;
int board[200001];
int dx[2] = {-1, 1};
queue<int> Q; 

void teleport(int a){
	while(a>0){
		a *= 2;
		if(a>=200000) break;
		if(board[a]!=-1) break;
		board[a] = board[a/2];
		Q.push(a);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fill(board, board+200000, -1);
	
	Q.push(n);
	board[n] = 0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		if(cur==k){
			cout << board[cur];
			return 0;
		}
		teleport(cur);
		for(int i=0; i<2; i++){
			int ncur = cur + dx[i];
			if(ncur>200000||ncur<0) continue;
			if(board[ncur]!=-1) continue;
			board[ncur] = board[cur] + 1;
			Q.push(ncur);
		}
	}
	
	return 0;
}