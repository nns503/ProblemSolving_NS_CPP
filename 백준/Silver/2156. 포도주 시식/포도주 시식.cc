#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
int dp[10001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}	
	
	dp[1] = arr[1];
	if(n >= 2) dp[2] = arr[2] + arr[1];
	for(int i=3; i<=n; i++){
		dp[i] = max(dp[i-2] + arr[i], max(dp[i-1], dp[i-3] + arr[i-1] + arr[i]));
	}
	
	cout << *max_element(dp, dp+n+1);
	return 0;
}
