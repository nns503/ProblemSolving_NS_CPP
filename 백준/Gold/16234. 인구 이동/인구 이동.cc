#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, l, r;
int board[101][101];
int answer = -1;
bool chk = true;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int plag[51][51];
int pop[2501];
int sum[2501];
queue<pair<int, int>> q;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= n);	
}

void BFS(int y, int x, int p){
	plag[y][x] = p;
	pop[p]++;
	sum[p] += board[y][x];
	q.push({y, x});
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(plag[ny][nx] != -1) continue;
			int num = abs(board[ny][nx] - board[cur.Y][cur.X]);
			if(num < l || num > r) continue;  
			plag[ny][nx] = p;
			pop[p]++; 
			sum[p] += board[ny][nx];
			q.push({ny, nx});
			chk = true;
		}	
	}
}

void setBoard(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int p = plag[i][j];
			board[i][j] = sum[p] / pop[p];
		}
	}	
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l >> r;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	
	while(chk){
		chk = false;
		answer++;
		int p = 0;
		for(int i=0; i<n; i++) fill(plag[i], plag[i]+n, -1);
		for(int i=0; i<n*n; i++){
			fill(pop, pop+n*n, 0);
			fill(sum, sum+n*n, 0);
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(plag[i][j] != -1) continue;
				BFS(i, j, p);
				p++;
			}
		}
		setBoard();
	}
	
	cout << answer;
	return 0;
}