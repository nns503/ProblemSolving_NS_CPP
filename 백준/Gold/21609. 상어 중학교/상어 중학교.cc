#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int temp[21][21];
int board[21][21];
bool vis[21][21];
pair<int, int> id;
int rbw;
int answer;
queue<pair<int, int>> q;
vector<pair<int, int>> block;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
const int blank = 9;

void printBoard(){
	cout << " \n";
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}	
}

void getTemp(){
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			temp[y][x] = board[y][x];
		}
	}	
}
void initVis(){
	for(int i=0; i<n; i++){
		fill(vis[i], vis[i]+n, false);
	}	
}

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= n);
}

void BFS(int y, int x){
	q.push({y, x});
	vis[y][x] = true;
	pair<int, int> cur_id = {y, x};
	int cur_rbw = 0;
	int cur_color = board[y][x];
	vector<pair<int, int>> cur_block;
	cur_block.push_back({y, x});
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(vis[ny][nx]) continue;
			if(board[ny][nx] == 0 || board[ny][nx] == cur_color){
				if(board[ny][nx] == 0){
					cur_rbw++;
				}
				else if(board[ny][nx] == cur_color){
					if(cur_id.Y > ny || (cur_id.Y == ny && cur_id.X > nx)){
						cur_id = {ny, nx};
					}
				}
				q.push({ny, nx});
				cur_block.push_back({ny, nx});
				vis[ny][nx] = true;
			}
		}
	}
	
	for(int i=0; i<cur_block.size(); i++){
		if(board[cur_block[i].Y][cur_block[i].X] == 0) vis[cur_block[i].Y][cur_block[i].X] = false;
	}
	
	if(cur_block.size() < block.size()) return;
	else if(cur_block.size() == block.size()){
		if(rbw > cur_rbw) return;
		else if(rbw == cur_rbw){
			if(cur_id.Y < id.Y) return;
			else if(cur_id.Y == id.Y){
				if(cur_id.X < id.X) return;
			}
		}
	}
	
	block.clear();
	rbw = cur_rbw;
	id = cur_id;
	for(int i=0; i<cur_block.size(); i++){
		block.push_back(cur_block[i]);
	}	
}

bool findBlock(){
	
	initVis();
	block.clear(); rbw = -1; 
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			if(board[y][x] < 1 || board[y][x] > m) continue;
			if(vis[y][x]) continue;
			BFS(y, x);
		}
	}
	
	if(block.size() < 2) return false;
	
	answer += block.size() * block.size();
	for(int i=0; i<block.size(); i++){
		board[block[i].Y][block[i].X] = blank;
	}
	return true;
}

void gravityBlock(){
	for(int x=0; x<n; x++){
		for(int k=0; k<n-1; k++){
			for(int y=0; y<n-1-k; y++){
				if(board[y][x] != -1 && board[y+1][x] == blank){
					board[y+1][x] = board[y][x];
					board[y][x] = blank;
				}
			}
		}
	}
}

void rotateBlock(){
	getTemp();
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			board[y][x] = temp[x][n-1-y];
		}
	}	
}



int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cin >> board[y][x];
		}
	}
	
	bool chk = true;
	while(chk){
		chk = findBlock();
		gravityBlock();
		rotateBlock();
		gravityBlock();
	}
	
	cout << answer;
	
	return 0;
}