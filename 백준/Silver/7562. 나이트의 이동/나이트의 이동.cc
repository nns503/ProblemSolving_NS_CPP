#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int board[301][301];
int check[301][301];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	
	cin >> T;
	
	for(int t=0;t<T;t++){
		pair<int, int> cur;
		pair<int, int> end;
		queue<pair<int, int>> Q;
				
		cin >> n;
		cin >> cur.X >> cur.Y;
		cin >> end.X >> end.Y;
		
		for(int i=0;i<n;i++) fill(check[i],check[i]+n,-1);
		Q.push({cur.X,cur.Y});
		check[cur.X][cur.Y]=0;
		while(!Q.empty()){
			cur = Q.front(); Q.pop();
			if(cur.X==end.X&&cur.Y==end.Y){
				cout << check[cur.X][cur.Y] << '\n';
				break;
			}
			for(int dir=0;dir<8;dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				if(check[nx][ny]!=-1) continue;
				check[nx][ny] = check[cur.X][cur.Y]+1;
				Q.push({nx,ny});
			}
		}
		
	}
	
	return 0;
}