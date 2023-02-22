#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

char board[12][6];
int answer = 0;
int dx[6] = {1,0,-1,0};
int dy[6] = {0,1,0,-1};
int vis[12][6];
bool boom = true;
pair<int, int> arr[80];
queue<pair<int, int>> Q;


void isPuyo(int y, int x){
	int cnt = 0;
	Q.push({y,x});
	vis[y][x] = true;
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		arr[cnt] = {cur.Y,cur.X};
		cnt++;
		Q.pop();
		for(int i=0;i<4;i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if(nx<0||ny<0||nx>=6||ny>=12) continue;
			if(vis[ny][nx]||board[cur.Y][cur.X]!=board[ny][nx]) continue;
			Q.push({ny,nx});
			vis[ny][nx]= true;
		}
	}
	if(cnt>=4){
		for(int i=0;i<cnt;i++){
			board[arr[i].Y][arr[i].X] = '.';
		}
		boom = true;
	}
}

void setBoard(){
	bool chg = true;
	while(chg){
		chg = false;
		for(int i=0;i<6;i++){
			for(int j=0;j<11;j++){
				if(board[j+1][i]=='.'&&board[j][i]!='.') {
					swap(board[j][i],board[j+1][i]);
					chg=true;
				}
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin >> board[i][j];
		}
	}
	while(boom){
		boom = false;
		for(int i=0;i<12;i++) fill(vis[i],vis[i]+6,false);
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){ 
				if(board[i][j]!='.'&&!vis[i][j]) {
					isPuyo(i,j);
				}
			}
		}
		if(boom) answer++;
		setBoard();
	}
	cout << answer;
}