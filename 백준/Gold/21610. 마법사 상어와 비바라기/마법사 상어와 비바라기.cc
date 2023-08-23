#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m; 
int d, s;
bool cloud[51][51];
int temp[51][51];
int board[51][51];
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
queue<pair<int, int>> q;

bool OOB(int y, int x){
	return (y <= 0 || x <= 0 || y > n || x > n);
}
 
int convertNum(int num){
	if(num <= 0){
		while(num <= 0){
			num += n;
		}
		return num;
	}
	else{
		return ((num-1) % n + 1);
	}	
}

void cloudToTemp(){
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			temp[y][x] = cloud[y][x];
		}
	}	
}

void dupleWater(){
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		
		for(int i=2; i<=8; i+=2){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == 0) continue;
			board[cur.Y][cur.X]++;
		}
	}
}

void setCloud(){
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			if(cloud[y][x]){
				cloud[y][x] = false;
			}
			else{
				if(board[y][x] >= 2){
					board[y][x] -= 2;
					cloud[y][x] = true;
				}
			}
		}
	}
}

void moveCloud(int d, int s){
	cloudToTemp();
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			int ny = convertNum(y + dy[d] * s);
			int nx = convertNum(x + dx[d] * s);
			cloud[ny][nx] = temp[y][x];
			if(cloud[ny][nx]){
				board[ny][nx]++;
				q.push({ny, nx});
			}
		}
	}
	
	dupleWater();
	setCloud();
}

int sumWater(){
	int sum = 0;
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			sum += board[y][x];
		}
	}	
	return sum;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			cin >> board[y][x];
		}
	}
	
	cloud[n][1] = true;
	cloud[n][2] = true;
	cloud[n-1][1] = true;
	cloud[n-1][2] = true;
	
	while(m--){
		cin >> d >> s;
		moveCloud(d, s);;
	}
	
	
	cout << sumWater();
	return 0;
}