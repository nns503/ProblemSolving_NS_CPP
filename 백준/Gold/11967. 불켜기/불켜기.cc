#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
bool light[101][101];
bool arr[101][101];
bool vis[101][101];
vector<pair<int ,int>> v[101][101];
queue<pair<int, int>> Q;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int answer;

bool OOB(int y, int x){
	return (y < 1 || x < 1 || y > n || x > n);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	while(m--){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[y][x].push_back({b, a});
	}
	
	Q.push({1, 1});
	light[1][1] = true;
	vis[1][1] = true;
	for(int j=0; j<v[1][1].size(); j++){
		pair<int, int> bt = v[1][1][j];
		light[bt.Y][bt.X] = true;
	}  
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(auto bt : v[cur.Y][cur.X]){
			if(!light[bt.Y][bt.X] && arr[bt.Y][bt.X]) Q.push({bt.Y, bt.X});
			light[bt.Y][bt.X] = true;
		}
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(vis[ny][nx]) continue;
			if(light[ny][nx]){
				vis[ny][nx] = true;
				Q.push({ny, nx});
			}
			else{
				arr[ny][nx] = true;
			}
			
		}
	}

	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(light[i][j]){
				answer++;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}