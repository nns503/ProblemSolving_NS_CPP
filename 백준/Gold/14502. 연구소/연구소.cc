#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, result;
int board[9][9];
int cpy[9][9];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> zero;
vector<int> v;
queue<pair<int, int>> Q;

int getSafety(){
	int answer = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m ;j++){
			if(cpy[i][j] == 0) answer++;
		}
	}	
	return answer;
}

void BFS(){	
	for(int i=0; i<n; i++){
		for(int j=0; j<m ;j++){
			if(cpy[i][j] == 2) {
				Q.push({i,j});
			}
		}
	}	
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
			if(cpy[ny][nx] != 0) continue;
			cpy[ny][nx] = 2;
			Q.push({ny, nx});
		}
	}
}

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m ;j++){
			cin >> board[i][j];
			if(board[i][j] == 0) zero.push_back({i,j});
		}
	}
	
	for(int i=0; i<zero.size(); i++){
		if(i<3) v.push_back(0);
		else v.push_back(1);
	}
	
	do{
		for(int i=0;i<n;i++){
			copy(board[i], board[i]+m, cpy[i]); 
		}		
		for(int i=0; i < zero.size(); i++){			
			if(v[i] == 0){
				cpy[zero[i].Y][zero[i].X] = 1;
			}
		}
		BFS();
		result = max(result, getSafety());
	}while(next_permutation(v.begin(), v.end()));
		
	cout << result;
	
	return 0;
}