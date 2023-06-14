#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[1011][1011];
int d[1011][1011];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;	
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			cin >> board[y][x];
		}
	}
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			d[y][x] = board[y][x] + max(d[y-1][x], d[y][x-1]);
		}
	}
	cout << d[n][m];
	return 0;
}

