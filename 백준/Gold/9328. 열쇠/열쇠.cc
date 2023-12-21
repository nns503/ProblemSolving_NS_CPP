#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int T, h, w;
string board[101];
bool vis[101][101];
bool alp[27];
vector<vector<pair<int, int>>> door(27, vector<pair<int, int>>()); 
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int answer;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= h || x >= w);
}

void BFS(int y, int x){
	vis[y][x] = true;
	q.push({y, x});
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			
			if(OOB(ny, nx)) continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = true;
			if(board[ny][nx] == '*') continue;	
			else{
				if(board[ny][nx] >= 'a' && board[ny][nx] <= 'z'){
					if(alp[board[ny][nx] - 'a'] == false){
						alp[board[ny][nx] - 'a'] = true;
						for(int l = 0; l<door[board[ny][nx] - 'a'].size(); l++){
							q.push({door[board[ny][nx] - 'a'][l].Y, door[board[ny][nx] - 'a'][l].X});
						}
					}
					q.push({ny, nx});
				}	
				else if(board[ny][nx] >= 'A' && board[ny][nx] <= 'Z'){
					if(alp[board[ny][nx] - 'A']){
						q.push({ny, nx});	
					}
					else{
						door[board[ny][nx] - 'A'].push_back({ny, nx});
					}
				}
				else if(board[ny][nx] == '$'){
					answer++;
					q.push({ny, nx});
				}
				else if(board[ny][nx] == '.'){
					q.push({ny, nx});
				}
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		answer = 0;
		fill(alp, alp+27, false);
		for(int i=0; i<=100; i++){
			fill(vis[i], vis[i]+101, false);
		}
		for(int i=0; i<27; i++){
			door[i].clear();
		}
		
		cin >> h >> w;
		
		for(int col=0; col<h; col++){
			cin >> board[col];	
		}
		
		string ky;
		cin >> ky;
		for(int i=0; i<ky.size(); i++){
			alp[ky[i] - 'a']= true;
		}
		
		for(int y=0; y<h; y++){
			for(int x=0; x<w; x++){
				if((y != 0 && y != h-1) && (x !=0 && x != w-1)) continue;
				if(vis[y][x]) continue;
				
				if(board[y][x] == '*') continue;	
				else if(board[y][x] >= 'a' && board[y][x] <= 'z'){
					if(alp[board[y][x] - 'a'] == false){
						alp[board[y][x] - 'a'] = true;
						for(int l = 0; l<door[board[y][x] - 'a'].size(); l++){
							q.push({door[board[y][x] - 'a'][l].Y, door[board[y][x] - 'a'][l].X});
						}
					}
					BFS(y, x);
				}	
				else if(board[y][x] >= 'A' && board[y][x] <= 'Z'){
					if(alp[board[y][x] - 'A']){
						BFS(y, x);
					}
					else{
						door[board[y][x] - 'A'].push_back({y, x});
					}
				}
				else if(board[y][x] == '$'){
					answer++;
					BFS(y, x);
				}
				else if(board[y][x] == '.'){
					BFS(y, x);
				}
								
	
			}
		}	
		
		cout << answer << '\n';
	}	
	
	return 0;
}
