#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

bool board[101][101];
bool check[101][101];
int m,n,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sx,ex,sy,ey;
	queue<pair<int,int>> Q;
	vector<int> v;
	
	cin >> m >> n >> k;
	
	while(k--){
		cin >> sx >> sy >> ex >> ey;
		for(int y=m-ey;y<m-sy;y++){
			for(int x=sx;x<ex;x++){
				board[y][x] = true;
			}
		}
	}
	
		
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==true) continue;
			int count = 1;
			board[i][j] = true;
			Q.push({i,j});
			while(!Q.empty()){
				pair<int,int> cur = Q.front(); Q.pop();
				for(int i=0;i<4;i++){
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];
					if(ny<0||ny>=m||nx<0||nx>=n) continue;
					if(board[ny][nx]==true) continue;
					board[ny][nx] = true;
					Q.push({ny,nx});
					count++;
				}
			}
			v.push_back(count);
		}
	}
	
	sort(v.begin(),v.end());
	
	cout << v.size() << '\n';
	for(auto a : v){
		cout << a << ' ';
	}
	return 0;
}
	
	
	
	