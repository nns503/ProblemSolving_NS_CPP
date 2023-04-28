#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int r, c;
string board[21];
bool alp[27];
int answer;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= r || x >= c);
}

void func(pair<int, int> p, int cnt){
	if(answer < cnt) answer = cnt;
	for(int i=0; i<4; i++){
		int ny = p.Y + dy[i];
		int nx = p.X + dx[i];
		if(OOB(ny, nx)) continue;
		int index = (board[ny][nx] - 'A');
		if(alp[index]) continue;
		alp[index] = true;
		func({ny, nx}, cnt+1);
		alp[index] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	for(int i=0; i<r; i++){
		cin >> board[i];
	}
	
	alp[board[0][0] - 'A'] = true;
	func({0, 0}, 1);
	
	cout << answer;
	return 0;
}