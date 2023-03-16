#include <bits/stdc++.h>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> dp;

long long solve(long long x){
	if(x == 0) return 1;
	if(dp[x] != 0) return dp[x];
	dp[x] = solve(x/p) + solve(x/q);
	return dp[x];
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	cin >> n >> p >> q;
	solve(n);
	
	cout << dp[n];
	return 0;
}
