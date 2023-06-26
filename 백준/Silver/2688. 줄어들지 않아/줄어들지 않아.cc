#include <bits/stdc++.h>

using namespace std;

int T;
int n;
long long dp[65][11];
long long sum[65];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sum[1] = 10;
	for(int i=1; i<=64; i++){
		for(int k=0; k<=9; k++){
			if(k == 0 || i == 1) dp[i][k] = 1;
			else{
				dp[i][k] = dp[i][k-1] + dp[i-1][k];
			}
			sum[i+1] += dp[i][k] * (10 - k);
		}
	}
	
	cin >> T;
	
	while(T--){
		cin >> n;
		cout << sum[n] << '\n';
	}
	
}
 