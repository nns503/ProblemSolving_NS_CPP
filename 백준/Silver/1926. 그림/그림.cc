#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool check[501][501];
int board[501][501];
int n,m;

int picture(int y, int x){
	int num = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	check[y][x] = true;
	
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny>=1&&nx>=1&&ny<=n&&nx<=m&&!check[ny][nx]&&board[ny][nx]==1){
				q.push(make_pair(ny,nx));
				check[ny][nx] = true;
				num++;
			}
		}
	}
	return num;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int large = 0;
	int count = 0;
		
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(board[i][j]!=1||check[i][j]==true) continue;
			int a = picture(i,j);
			large = max(a,large);
			count++;
		}
	}
	
	cout << count << '\n' << large;
	
	return 0;
}