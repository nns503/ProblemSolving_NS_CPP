#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool checkMap(int m, int n){
	for(int y=1;y<=n;y++){
		for(int x=1;x<=m;x++){
			if(map[y][x] == 0) return false;
		}
	}	
	return true;
}

int main(void){
	int day = 1;
	int m,n;
	queue<pair<int,int>> q;

	cin >> m >> n;
	for(int y=1;y<=n;y++){
		for(int x=1;x<=m;x++){
			cin >> map[y][x];
			if(map[y][x] == 1) q.push(make_pair(y,x)); 
		}
	}
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		if(map[p.first][p.second]!=day){
			day++;
		}		
		for(int i=0;i<4;i++){
			int ny = p.first+dy[i];
			int nx = p.second+dx[i];
			if(ny>=1&&nx>=1&ny<=n&&nx<=m&&map[ny][nx]==0){
				map[ny][nx] = day + 1;
				q.push(make_pair(ny,nx));
			}
		}
		q.pop();
	}
	
	if(checkMap(m,n)) cout << day-1;
	else cout << -1;
	
	
	return 0;
}