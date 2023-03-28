#include <bits/stdc++.h>

using namespace std;

long long dp[1001][11];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int j=0; j<=9; j++) dp[1][j] = 1;
	dp[1][10] = 10;
	
	for(int i = 2; i<= n; i++){
		long long mn = 0;
		for(int j=0; j<=9; j++){
			dp[i][j] = (dp[i-1][10] - mn) % 10007;
			mn += dp[i-1][j] % 10007;
			dp[i][10] += dp[i][j] % 10007;
		}
	}
	
	cout << dp[n][10] % 10007;
	return 0;
}
