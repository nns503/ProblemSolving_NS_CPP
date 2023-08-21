#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int a, b;
int n, m;
int board[101][101];
int dir[101];
pair<int, int> rob[101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
queue<tuple<int, char, int>> Q;
bool OOB(int y, int x){
	return {y > b || x > a || x <= 0 || y <= 0};
}

int convertDir(char c){
	if(c == 'N') return 0;
	else if(c == 'E') return 1;
	else if(c == 'S') return 2;
	else if(c == 'W') return 3; 
}

void moveRob(int i, char c){
	if(c == 'L'){
		dir[i] += 3;
		dir[i] %= 4;
	}
	else if(c == 'R'){
		dir[i] += 1;
		dir[i] %= 4;
	}
	else if(c == 'F'){
		rob[i] = {rob[i].Y + dy[dir[i]], rob[i].X + dx[dir[i]]}; 
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		int y, x; char c;
		cin >> x >> y >> c;
		board[y][x] = i;
		rob[i] = {y, x};
		dir[i] = convertDir(c);
	}
	
	while(m--){
		int q, w; char c;
		cin >> q >> c >> w;
		Q.push(make_tuple(q, c, w));
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int q, w; char c;
		tie(q, c, w) = cur;
		board[rob[q].Y][rob[q].X] = 0;
		while(w--){
			moveRob(q, c);
			if(OOB(rob[q].Y, rob[q].X)){
				cout << "Robot " << q << " crashes into the wall";
				return 0;
			}
			if(board[rob[q].Y][rob[q].X] != 0){
				cout << "Robot " << q << " crashes into robot " << board[rob[q].Y][rob[q].X];
				return 0;
			}
		}
		board[rob[q].Y][rob[q].X] = q;
	}
	
	cout << "OK";
	return 0;
}