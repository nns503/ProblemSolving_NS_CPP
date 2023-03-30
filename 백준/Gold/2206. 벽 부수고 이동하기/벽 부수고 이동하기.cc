#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
string board[1001];
int vis[1001][1001][2];
queue<tuple<int, int, int>> Q;

int main(void){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> board[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			vis[i][j][0] = -1;
			vis[i][j][1] = -1;
		}
	}
	Q.push(make_tuple(0, 0, 1));
	vis[0][0][1] = 1;
	while(!Q.empty()){
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		int y = get<0>(cur);
		int x = get<1>(cur);
		int bk = get<2>(cur);
		if(y == n-1 & x == m-1){
			cout << vis[y][x][bk];
			return 0;
		}
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny<0 || nx<0 || ny >= n || nx >= m) continue;
			if(vis[ny][nx][bk]!=-1) continue;
			if(bk == 1){
				if(board[ny][nx] == '1'){
					Q.push(make_tuple(ny, nx, bk-1));
					vis[ny][nx][bk-1] = vis[y][x][bk] + 1;
				}
				else if(board[ny][nx] == '0'){
					Q.push(make_tuple(ny, nx, bk));	
					vis[ny][nx][bk] = vis[y][x][bk] + 1;
				}
			}
			else{
				if(board[ny][nx] == '0'){
					vis[ny][nx][bk] = vis[y][x][bk] + 1;
					Q.push(make_tuple(ny, nx, bk));	
				}
			}
		} 
	}
	cout << -1;	
	return 0;
}