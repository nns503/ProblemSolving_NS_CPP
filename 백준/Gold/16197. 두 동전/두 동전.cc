#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
char board[21][21];
bool vis1[21][21];
bool vis2[21][21];
int answer = 11;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

bool chkWall(int y, int x){
	return (board[y][x] == '#');
}

int chkBound(int y, int x){
	if(OOB(y, x)) return 2;
	if(chkWall(y, x)) return 1;
	return 0;
}

void func(pair<int, int> p1, pair<int, int> p2, int cnt){
	if(cnt == 11) return ;
	
	if(answer <= cnt) return ;
	
	for(int i=0; i<4; i++){
		int ny1 = p1.Y + dy[i];
		int nx1 = p1.X + dx[i];
		int ny2 = p2.Y + dy[i];
		int nx2 = p2.X + dx[i];
		int chk1 = chkBound(ny1, nx1);
		int chk2 = chkBound(ny2, nx2);
		
		if(chk1 == 2 && chk2 == 2) continue;
		
		if(chk1 == 2 || chk2 == 2){
			answer = min(cnt, answer);
			return;
		}
		
		
		if(chk1 == 1){
			ny1 = p1.Y;
			nx1 = p1.X;
		}
		if(chk2 == 1){
			ny2 = p2.Y;
			nx2 = p2.X;
		}
		
		if(p1.Y == p2.Y && p1.X == p2.X) continue;

		func({ny1, nx1}, {ny2, nx2}, cnt+1);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	bool chk = false;
	pair<int, int> p1, p2;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cin >> board[y][x];
			if(board[y][x] == 'o' && !chk){
				vis1[y][x] = true;
				p1 = {y, x};
				chk = true;
			}
			else if(board[y][x] == 'o' && chk){
				vis2[y][x] = true;
				p2 = {y, x};
			}
		}
	}

	func(p1, p2, 1);
	
	if(answer == 11) cout << -1;
	else cout << answer;
	
	return 0;
}
