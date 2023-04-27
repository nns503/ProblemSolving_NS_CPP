#include <bits/stdc++.h>
using namespace std;

int n;
int r, c;
int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};
bool board[17][17];
queue<tuple<int, int, int>> Q; // 상태, y, x 
// 0 가로, 1 세로, 2 대각선 
int answer;

bool OOB(int y, int x){
	return (y <= 0 || x <= 0 || y > n || x > n);
}

bool isWid(int y, int x){
	return !(OOB(y, x+1) || board[y][x+1]);
}

bool isHei(int y, int x){
	return !(OOB(y+1, x) || board[y+1][x]);
}

bool isDia(int y, int x){
	return !(!isWid(y, x) || !isHei(y, x) || OOB(y+1, x+1) || board[y+1][x+1]);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> board[i][j];
		}
	}
	
	Q.push(make_tuple(0, 1, 2));
	
	while(!Q.empty()){
		int p, y, x;
		tie(p, y, x) = Q.front(); Q.pop();
		if(y == n && x == n){
			answer++;
			continue;
		}
		if(p == 0){
			if(isWid(y, x)) Q.push(make_tuple(0, y, x+1));
			if(isDia(y, x)) Q.push(make_tuple(2, y+1, x+1));
		}
		else if(p == 1){
			if(isHei(y, x)) Q.push(make_tuple(1, y+1, x));
			if(isDia(y, x)) Q.push(make_tuple(2, y+1, x+1));
		}
		else if(p == 2){
			if(isWid(y, x)) Q.push(make_tuple(0, y, x+1));
			if(isHei(y, x)) Q.push(make_tuple(1, y+1, x));
			if(isDia(y, x)) Q.push(make_tuple(2, y+1, x+1));
		}
	}
	
	cout << answer;
	return 0;
}