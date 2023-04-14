#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int s = 2;
int e;
int n, cnt;
int board[21][21];
int dist[21][21];
int vis[21][21];
queue<pair<int, int>> Q;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1 ,0};
vector<pair<int, int>> temp;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	if(p1.Y == p2.Y) return p1.X < p2.X;
	return p1.Y < p2.Y;
}

bool OOB(int y, int x){
	return (y >= n || x >= n || y < 0 || x < 0);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			vis[i][j] = -1;
			cin >> board[i][j];
			if(board[i][j] == 9){
				board[i][j] = 0;
				Q.push({i, j});
				vis[i][j] = cnt;
			} 
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(vis[ny][nx] >= cnt) continue;
			if(board[ny][nx] > s) continue;
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
			vis[ny][nx] = cnt;
			if(board[ny][nx] == 0 || board[ny][nx] == s)	Q.push({ny, nx});
			else temp.push_back({ny, nx});
		}
		if(Q.empty() || dist[Q.front().Y][Q.front().X] == dist[cur.Y][cur.X] + 1){
			if(!temp.empty()){
				sort(temp.begin(), temp.end(), cmp);
				auto del = temp[0]; temp.clear();
				board[del.Y][del.X] = 0;
				e++;
				if(e == s){
					e = 0;
					s++;
				}
				cnt += dist[del.Y][del.X];
				dist[del.Y][del.X] = 0;
				vis[del.Y][del.X] = cnt;
				while(!Q.empty()) Q.pop();
				Q.push({del.Y, del.X});
			}
		}
	}
	
	cout << cnt;
	
	
	return 0;
}