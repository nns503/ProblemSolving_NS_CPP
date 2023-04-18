#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int dp[1001];
int card[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> card[i];
	}
	
	
	for(int i=1; i<=n; i++){
		dp[i] = card[i];
		for(int j=0; i-j>=j; j++){
			dp[i] = max(dp[i], dp[i-j] + dp[j]);
		}
	}
	
	cout << dp[n];
	
	return 0;
}