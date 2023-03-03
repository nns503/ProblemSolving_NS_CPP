#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int answer;
int n, k, p, m;
int mx = 1, my = 1;
int board[101][101];
bool vis[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, char>> Q;
queue<pair<int, int>> S;

bool isOutBoard(){
	return (mx<1 || my<1 || mx>n || my>n);
}


int main(void){
	cin >> n >> k;
	while(k--){
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	cin >> p;
	
	while(p--){
		int a; char b;
		cin >> a >> b;
		Q.push({a, b});
	}

	vis[my][mx] = true;
	S.push({my, mx});	

	for(int t=1; t<=10000; t++){
		my = my + dy[m];
		mx = mx + dx[m];

		if(isOutBoard() || vis[my][mx]){
			answer = t; 
			cout << answer;
			return 0;
		}
		
		vis[my][mx] = true;
		S.push({my, mx});	
		
		if(board[my][mx] == 1){
			board[my][mx] = 0;
		}
		else{
			vis[S.front().Y][S.front().X] = false;
			S.pop();
		}
		
		if(!Q.empty()&&Q.front().Y == t){
			if(Q.front().X=='D') m += 1;
			else m += 3;
			m %= 4;
			Q.pop();
		}	
	}
}