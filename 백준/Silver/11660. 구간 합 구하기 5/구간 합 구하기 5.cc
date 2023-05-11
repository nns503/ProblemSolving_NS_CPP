#include <bits/stdc++.h>

using namespace std;

int board[1025][1025];
int w[1025][1025];
int h[1025][1025];
int n, m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i][j];
		}
	}
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=n; x++){
			w[y][x] = w[y][x-1] + board[y][x];
		}
	}
		
	while(m--){
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		int answer = 0;
		for(int y=y1; y<=y2; y++){
			answer += w[y][x2] - w[y][x1-1];
		}
		cout << answer << '\n';
	}
	return 0;
}