#include <bits/stdc++.h>
#define X first 
#define Y second 

using namespace std;
 
string board[101];
bool check[101][101];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n_1=0, n_2=0;
	queue<pair<int,int>> Q;
	
	// 입력 
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> board[i];
	}
	// 탐색 
	for(int i=0;i<n;i++) fill(check[i],check[i]+n,false);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check[i][j]==true) continue;
			n_1++;
			Q.push({i,j});
			check[i][j] = true;
			while(!Q.empty()){
				pair<int,int> cur = Q.front();
				Q.pop();
				for(int k=0;k<4;k++){
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if(nx<0||ny<0||nx>=n||ny>=n) continue;
					if(check[nx][ny]) continue;
					if(board[nx][ny]!=board[cur.X][cur.Y]) continue;
					Q.push({nx,ny});
					check[nx][ny] = true;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++) fill(check[i],check[i]+n,false);	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]=='G') board[i][j]='R';
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check[i][j]==true) continue;
			n_2++;
			Q.push({i,j});
			check[i][j] = true;
			while(!Q.empty()){
				pair<int,int> cur = Q.front();
				Q.pop();
				for(int k=0;k<4;k++){
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if(nx<0||ny<0||nx>=n||ny>=n) continue;
					if(check[nx][ny]) continue;
					if(board[nx][ny]!=board[cur.X][cur.Y]) continue;
					Q.push({nx,ny});
					check[nx][ny] = true;
				}
			}
		}	
	}
	cout << n_1 << " " << n_2;
	
	
	return 0;
}