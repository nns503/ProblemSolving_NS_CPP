#include <bits/stdc++.h>
using namespace std;

int dp[17];
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		int t, p;
		cin >> t >> p;
		if(i+t-1 > n) continue;
		dp[i] = max(dp[i], dp[i-1]);
		dp[i+t] = max(dp[i+t], dp[i] + p);
	}	
	
	cout << *max_element(dp, dp+17);
	
	return 0;
}