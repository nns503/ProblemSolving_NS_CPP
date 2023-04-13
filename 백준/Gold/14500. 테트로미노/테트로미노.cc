#include <bits/stdc++.h>
using namespace std;

int answer;
int sum;
int n, m;
int board[501][501];
int vis[501][501];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool oh1[2][2][3] = {{{1, 1, 1}, {0, 1, 0}}, {{0, 1, 0}, {1, 1, 1}}};
bool oh2[2][3][2] = {{{1, 0}, {1, 1}, {1, 0}}, {{0, 1}, {1, 1}, {0, 1}}};

int OOB(int y, int x){
	return (y >= n || y < 0 || x >= m || x < 0);
}

void DFS(int y, int x, int cnt){
	if(cnt == 4){
		answer = max(answer, sum);
		return ; 
	}
	for(int i=0; i<4; i++){
		if(vis[y][x]) continue;
		if(OOB(y + dy[i], x + dx[i])) continue;
		vis[y][x] = true;
		sum += board[y][x];
		DFS(y + dy[i], x + dx[i], cnt+1);
		vis[y][x] = false;
		sum -= board[y][x];
	}
}

int func(int y, int x){
	int mx = 0;
	if(!OOB(y+1, x+2)){
		for(int k=0; k<2; k++){
			int temp = 0;
			for(int i=0; i<2; i++){
				for(int j=0; j<3; j++){
					if(oh1[k][i][j]){
						temp += board[y + i ][x + j];
					}
				}
			}
			mx = max(temp, mx);
		}
	}
	if(!OOB(y+2, x+1)){
		for(int k=0; k<2; k++){
			int temp = 0;
			for(int i=0; i<3; i++){
				for(int j=0; j<2; j++){
					if(oh2[k][i][j]){
						temp += board[y + i][x + j];
					}
				}
			}
			mx = max(temp, mx);
		}		
	}
	return mx;
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
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			DFS(y, x, 0);
			answer = max(answer, func(y, x));
		}
	}	
	
	cout << answer;
	
	return 0;
}