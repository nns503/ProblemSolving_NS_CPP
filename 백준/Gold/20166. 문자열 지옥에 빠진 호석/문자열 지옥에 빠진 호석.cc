#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

unordered_map<string, int> um;
queue<pair<string, pair<int, int>>> q;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char board[11][11];
int n, m, k;
string target;

void func(int y, int x){
	string s;
	s.push_back(board[y][x]);
	q.push({s, {y, x}});
	um[s]++;
	while(!q.empty()){
		auto cur = q.front().X; 
		string text = q.front().Y; q.pop();
		for(int i=0; i<8; i++){
			string temp = text;
			int ny = dy[i] + cur.Y;
			int nx = dx[i] + cur.X;
			
			if(ny <= 0) ny = n; if(nx <= 0) nx = m;
			if(ny > n) ny = 1; if(nx > m) nx = 1;
			
			temp.push_back(board[ny][nx]);
			um[temp]++;
			if(temp.size() < 5){	
				q.push({temp, {ny, nx}});
			}
		}
	}
}
 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			cin >> board[y][x];
		}
	}

	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			func(y, x);
		}
	}
	
	while(k--){
		cin >> target;
		cout << um[target] << '\n';
	}

	return 0;	
}