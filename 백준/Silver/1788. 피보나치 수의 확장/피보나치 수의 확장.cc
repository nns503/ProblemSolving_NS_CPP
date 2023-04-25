#include <bits/stdc++.h>

using namespace std;

long long dp[1000001];
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	
	for(int i=3; i<=1000001; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 1000000000;	
	}
	
	cin >> n;
	
	if(n > 0){
		cout << 1 << '\n';
		cout << dp[n];
	}	
	else if(n == 0){
		cout << 0 << '\n' << 0;
	}
	else{
		n = abs(n);
		if(n % 2 == 0) cout << -1 << '\n' << dp[n];
		else cout << 1 << '\n' << dp[n];
	}
	return 0;
}