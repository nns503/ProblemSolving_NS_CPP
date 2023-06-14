#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, p;
string board[1001];
int d[10];
queue<tuple<int, int, int>> Q;
queue<tuple<int, int, int>> q;

bool OOB(int y, int x){
	return ( y >= n || x >= m || y < 0 || x < 0);
}


int main(void){

	cin >> n >> m >> p;
	
	for(int i=1; i<=p; i++) cin >> d[i];
	
	for(int y=0; y<n; y++) cin >> board[y];
	
	for(int k=1; k<=p; k++){
		for(int y=0; y<n; y++){
			for(int x=0; x<m; x++){
				if(board[y][x] - '0' == k){
					Q.push(make_tuple(y, x, k));
				} 
			}
		}
	}
	
	while(!Q.empty()){
		int prev = get<2>(Q.front());
		while(!Q.empty() && get<2>(Q.front()) == prev){
			auto c = Q.front(); Q.pop();
			int y, x, k;
			tie(y, x, k) = c;
			q.push(make_tuple(y, x, 1));
			prev = k;
		}
		while(!q.empty()){
			auto cur = q.front(); q.pop();
			int cy, cx, cn;
			tie(cy, cx, cn) = cur;
			for(int i=0; i<4; i++){
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(OOB(ny, nx)) continue;
				if(board[ny][nx] != '.') continue;
				board[ny][nx] = ('0' + prev);
				if(cn < d[prev]) q.push(make_tuple(ny, nx, cn+1));
				else if(cn == d[prev]) Q.push(make_tuple(ny, nx, prev)); 
			}
		}
	}
	
	for(int k=1; k<=p; k++){
		int answer = 0;
		for(int y=0; y<n; y++){
			for(int x=0; x<m; x++){
				if(board[y][x] - '0' == k){
					answer++;
				} 
			}
		}
		cout << answer << ' ';
	}
	
	return 0;
}