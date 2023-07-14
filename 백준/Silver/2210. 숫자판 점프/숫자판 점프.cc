#include <bits/stdc++.h>

using namespace std;

char board[6][6];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
set<string> s;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= 5 || x >= 5);
}

void func(int y, int x, string num){
	
	if(num.size() == 6){
		s.insert(num);
		return ;
	}
	
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(OOB(ny, nx)) continue;
		func(ny, nx, num + board[ny][nx]);	
	}
} 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			string s; s.push_back(board[i][j]);
			func(i, j, s);
		}
	}	
	
	cout << s.size();
	return 0;
}