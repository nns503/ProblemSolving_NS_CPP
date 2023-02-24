#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n,m;
int board[305][305];
bool vis[305][305];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> Q;

void BFS(int y, int x){
	Q.push({y,x});
	vis[y][x] = true;
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(vis[ny][nx]|board[ny][nx]==0) continue;
			vis[ny][nx] = true;
			Q.push({ny,nx});
		}
	}
}

int isBoard(){
	for(int i=0;i<n;i++) fill(vis[i], vis[i]+m, false);
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]!=0&&!vis[i][j]){
				BFS(i,j);
				cnt++;	 
				if(cnt==2) return 2;
			}
		}
	}
	if(cnt==1) return 1;
	else if(cnt==0) return 3;
}

void setBoard(){
	int temp[305][305];
	for(int y=0;y<n;y++){
		for(int x=0;x<m;x++) temp[y][x] = board[y][x];
	}
	
	for(int y=1;y<n-1;y++){
		for(int x=1;x<m-1;x++){
			if(board[y][x]==0) continue;
			for(int k=0;k<4;k++){		
				int ny = y + dy[k];
				int nx = x + dx[k];
				if(temp[ny][nx]==0) board[y][x]--;			
				if(board[y][x]==0) break;
			}
		}
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin >> board[i][j];
	}
	
	int answer = 0;
	while(true){
		int c = isBoard();
		if(c==3){
			cout << 0;
			return 0;
		}
		else if(c==2){
			cout << answer;
			return 0;
		}
		else if(c==1){
			setBoard();
			answer++;
		}
	}
}