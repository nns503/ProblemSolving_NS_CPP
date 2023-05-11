#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n;
int board[126][126];
int rp[126][126];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= n);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	while(++T){
		cin >> n;
		if(n == 0) break;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> board[i][j];
			}
		}
		for(int i=0; i<n; i++) fill(rp[i], rp[i]+n, 100000);
		queue<pair<int, int>> Q;
		rp[0][0] = board[0][0];
		Q.push({0, 0});
		
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			for(int i=0; i<4; i++){
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];
				if(OOB(ny, nx)) continue;
				if(rp[ny][nx] <= rp[cur.Y][cur.X] + board[ny][nx]) continue;
				rp[ny][nx] = rp[cur.Y][cur.X] + board[ny][nx];
				Q.push({ny, nx});
			}
		}
		cout << "Problem " << T << ": " << rp[n-1][n-1] << '\n';
	}
	return 0;
}