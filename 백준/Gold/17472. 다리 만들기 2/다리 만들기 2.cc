#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int board[11][11]; 
int flag[11][11];
int dist[11][11][4];
queue<pair<int, int>> q;
queue<tuple<int, int, int>> Q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int number;
int answer;
vector<pair<int, int>> point;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

void setDist(){
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			for(int i=0; i<4; i++) dist[y][x][i] = -1;
		}
	}
}

void setFlag(pair<int, int> p){
	setDist();
	q.push(p);
	flag[p.Y][p.X] = number;
	dist[p.Y][p.X][0] = 0;
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == 0) continue;
			if(dist[ny][nx][0] != -1) continue;
			if(flag[ny][nx] != 0) continue;
			dist[ny][nx][0] = 0;
			flag[ny][nx] = number;
			q.push({ny, nx});
		}
	}
}

void changeFlag(int curflag, int toflag){
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(flag[y][x] == toflag){
				point.push_back({y, x});
				flag[y][x] = curflag;
			}
		}
	}		
}

bool setBri(){
	
	setDist();
	for(int i=0; i<point.size(); i++){
		Q.push(make_tuple(point[i].Y, point[i].X, 0));
		Q.push(make_tuple(point[i].Y, point[i].X, 2));	
		for(int k=0; k<4; k++) dist[point[i].Y][point[i].X][k] = 0;	
	}
	int curflag = 1;
	
	while(!Q.empty()){
		int y, x, dir;
		tie(y, x, dir) = Q.front(); Q.pop();
		for(int i=dir; i<dir+2; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(OOB(ny, nx)) continue;
			if(dist[ny][nx][i] != -1) continue;
			if(board[ny][nx] == 0){
				dist[ny][nx][i] = dist[y][x][i] + 1;
				Q.push(make_tuple(ny, nx, dir));
			}
			else if(board[ny][nx] == 1 && flag[ny][nx] != curflag){
				if(dist[y][x][i] < 2) continue;
				changeFlag(curflag, flag[ny][nx]);
				answer += dist[y][x][i];
				number--;
				while(!Q.empty()) Q.pop();
				return true;
			}
		}
	}
	return false;
}

int main(void){
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cin >> board[y][x];
		}
	}	

	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(board[y][x] == 0 || flag[y][x] != 0) continue;
			number++;
			setFlag({y, x});
		}
	}	
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(flag[y][x] == 1){
				point.push_back({y, x});
			}
		}
	}

	
	while(number>1){
		bool chk = setBri();
		if(!chk){
			cout << "-1";
			return 0;
		}

	}
	
	cout << answer;
	
	return 0;
}