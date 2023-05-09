#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[10001];
int c[10001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(dp, dp+10001, 100000);
	dp[0] = 0;
	
	cin >> n >> k;
	while(n--){
		int a;
		cin >> a;
		
		int cnt = 0;
		for(int i=a; i<=k; i++){
			if(i % a == 0) cnt++;
			dp[i] = min(dp[i-a] + 1, dp[i]);
		}
	}
	
	cout << (dp[k] == 100000 ? -1 : dp[k]);
	return 0;
}