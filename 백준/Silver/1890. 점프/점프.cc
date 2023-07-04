#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101];
long long dp[101][101];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cin >> board[y][x];
		}
	}
	
	dp[0][0] = 1;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			if(y == n-1 && x == n-1) break;
			int cur = board[y][x];
			if(y + cur < n) dp[y+cur][x] += dp[y][x];
			if(x + cur < n) dp[y][x+cur] += dp[y][x];
		}		
	}
	
	cout << dp[n-1][n-1];
	return 0;
}