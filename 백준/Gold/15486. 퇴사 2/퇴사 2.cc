#include <bits/stdc++.h>
using namespace std;

long long dp[1500010];
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		int t, p;
		cin >> t >> p;
		dp[i] = max(dp[i], dp[i-1]);
		if(i+t-1 > n) continue;
		dp[i+t] = max(dp[i+t], dp[i] + p);
	}	
	
	cout << max(dp[n], dp[n+1]);
	
	return 0;
}