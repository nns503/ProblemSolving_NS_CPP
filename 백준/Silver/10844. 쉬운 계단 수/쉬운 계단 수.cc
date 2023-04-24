#include <bits/stdc++.h>

using namespace std;

int n;
long long answer;
int dp[101][10];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	
	for(int i=1; i<=9; i++){
		dp[1][i] = 1;
	}
	
	for(int i=2; i<=100; i++){
		for(int j=1; j<=8; j++){
			dp[i][j] += dp[i-1][j-1] % 1000000000;
			dp[i][j] += dp[i-1][j+1] % 1000000000;
		}
		dp[i][0] += dp[i-1][1] % 1000000000;
		dp[i][9] += dp[i-1][8] % 1000000000;
	}
	
	for(auto a : dp[n]){
		answer += (a % 1000000000);
	}
	
	cout << answer % 1000000000;
	
	return 0;
}