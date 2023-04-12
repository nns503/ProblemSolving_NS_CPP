#include <bits/stdc++.h>

using namespace std;

int dp[50001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=1; i*i<=50001; i++){
		dp[i*i] = 1;
	}
	
	for(int i=1; i<=50001; i++){
		int temp = 4;
		for(int j=1; j*j<=i; j++){
			temp = min(temp, dp[j*j] + dp[i - j*j]);
		}
		dp[i] = temp;	
	}
	
	cout << dp[n];
	return 0;
}
