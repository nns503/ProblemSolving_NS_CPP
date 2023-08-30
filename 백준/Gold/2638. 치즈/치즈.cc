#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int n, m, answer;
int board[101][101];
bool vis[101][101]; 
int cnt[101][101];
int t[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;


bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

void bfsAir(int y, int x){
	queue<pair<int, int>> cq;
	cq.push({y, x});
	
	while(!cq.empty()){
		auto cur = cq.front(); cq.pop();
		
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(vis[ny][nx]) continue;
			
			if(board[ny][nx] == 0){
				vis[ny][nx] = true;
				cq.push({ny, nx});
				t[ny][nx] = t[cur.Y][cur.X];
			}
			else if(board[ny][nx] == 1){ 
				cnt[ny][nx]++;
				if(cnt[ny][nx] >= 2){
					vis[ny][nx] = true;
					q.push({ny, nx});
					t[ny][nx] = t[cur.Y][cur.X] + 1;	
				}
			}
		}
	}	
}

void BFS(){
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		bfsAir(cur.Y, cur.X);
	}
}

void printBoard(){
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cout << t[y][x] << ' ';
		}
		cout << '\n';
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cin >> board[y][x];
		}
	}
	
	vis[0][0] = true;
	bfsAir(0, 0);
	BFS();

	for(int y=0; y<n; y++){
		answer = max(answer, *max_element(t[y], t[y]+m));
	}
	cout << answer;
	return 0;
}