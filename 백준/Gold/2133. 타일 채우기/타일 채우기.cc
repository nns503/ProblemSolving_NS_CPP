#include<bits/stdc++.h>

using namespace std;

int dp[31];
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;	

	for(int i=6; i<=30; i++){
		if(!(i % 2)){
			dp[i] = dp[i-2] * 3 + dp[i-4] * 3 - dp[i-6];
		}
	}
	
	cin >> n;	
	cout << dp[n];
	return 0;
}

