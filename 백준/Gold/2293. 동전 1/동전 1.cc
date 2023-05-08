#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int n, k;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	dp[0] = 1;
	
	while(n--){
		int a;
		cin >> a;
		for(int i=a; i<=k; i++){
			dp[i] += dp[i-a];
		}
	}
	
	cout << dp[k];	
	return 0;
}