#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[91];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	dp[1] = 1;
	
	for(int i = 2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	cout << dp[n];
	
	return 0;
}
