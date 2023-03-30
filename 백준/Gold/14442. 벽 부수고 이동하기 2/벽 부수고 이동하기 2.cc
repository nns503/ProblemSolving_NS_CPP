#include <bits/stdc++.h>

using namespace std;

int n, m, k;
string board[1001];
int dist[1001][1001][11];
queue<tuple<int, int, int>> q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y >= n || x >= m || y < 0 || x < 0);	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) cin >> board[i];

	dist[0][0][k]= 1;
	q.push(make_tuple(0, 0, k));
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		int cy = get<0>(cur);
		int cx = get<1>(cur);
		int ck = get<2>(cur);
		if(cy == n-1 && cx == m-1){
			cout << dist[cy][cx][ck];
			return 0;
		}
		for(int i=0; i<4; i++){
			int ny = get<0>(cur) + dy[i];
			int nx = get<1>(cur) + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == '0' && dist[ny][nx][ck] == 0){
				dist[ny][nx][ck] = dist[cy][cx][ck] + 1;
				q.push(make_tuple(ny, nx, ck));
			}
			else if(ck != 0 && board[ny][nx] == '1' && dist[ny][nx][ck-1] == 0){
				dist[ny][nx][ck-1] = dist[cy][cx][ck] + 1;
				q.push(make_tuple(ny, nx, ck-1));
			}
		}	
	}
	
	cout << -1;
	return 0;
}