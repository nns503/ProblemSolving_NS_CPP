#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k, dir;
int board[21][21];
int cur[5];
int d[7];
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
vector<int> s(6); 

bool OOB(int ny, int nx){
	return (ny >= n || nx >= m || ny < 0 || nx < 0);
}

void turnCur(int dir){
	if(dir == 1){ //east
		s = {s[3], s[0], s[2], s[5], s[4], s[1]};
	}
	else if(dir == 2){
		s = {s[1], s[5], s[2], s[0], s[4], s[3]};
	}
	else if(dir == 3){
		s = {s[2], s[1], s[5], s[3], s[0], s[4]};
	}
	else if(dir == 4){
		s = {s[4], s[1], s[0], s[3], s[5], s[2]};
	}
}
	

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	s = {1, 3, 5, 4, 2, 6};
	
	cin >> n >> m >> y >> x >> k;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	while(k--){
		cin >> dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(OOB(ny, nx)) continue;
		turnCur(dir);
		if(board[ny][nx] == 0){
			board[ny][nx] = d[s[5]];	
		}
		else{
			d[s[5]] = board[ny][nx];
			board[ny][nx] = 0;
		}
		
		y = ny; x = nx;
		cout << d[s[0]] << '\n';
	}
	return 0;
}