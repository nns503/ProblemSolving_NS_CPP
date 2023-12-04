#include <bits/stdc++.h>

using namespace std;

int board[1025][1025];
int sum[1025][1025];
int n, m, k;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> board[i][j];
		}
	}
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			sum[y][x] = sum[y][x-1] + board[y][x];		
		}
	}
	
	cin >> k;
	
	for(int i=0; i<k; i++){
		int y1, x1, y2, x2;
		int temp = 0;
		cin >> y1 >> x1 >> y2 >> x2;
		
		for(int y=y1; y<=y2; y++){
			temp += sum[y][x2] - sum[y][x1-1];
		}
		
		cout << temp << '\n';
	}
	
	return 0;
}