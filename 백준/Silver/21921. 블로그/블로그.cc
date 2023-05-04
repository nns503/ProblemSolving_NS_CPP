#include <bits/stdc++.h>

using namespace std;

int dp[250001];
int num[250001];
int n, x;
int mx;
int cnt;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	
	for(int i=1; i<=n; i++){
		cin >> num[i];
		if(i <= x){
			dp[i] = dp[i-1] + num[i];
		}
		else{
			dp[i] = dp[i-1] + num[i] - num[i-x];
		}
	}
	
	sort(dp, dp+n+1, greater<int>());
	
	cnt = 1;
	for(int i=1; i<n; i++){
		if(dp[i-1] != dp[i]) break;
		cnt++;
	}
	
	if(dp[0] == 0) cout << "SAD";
	else{
		cout << dp[0] << '\n' << cnt;
	}
	return 0;
}