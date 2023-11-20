#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n; 
long long dp[102][21];
int num[101];
long long answer;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> num[i];
	}
	
	dp[1][num[1]]++;
	
	for(int i=2; i<=n-1; i++){
		for(int k=0; k<=20; k++){
			int p = k + num[i];
			int m = k - num[i];
			if(p <= 20){
				dp[i][p] += dp[i-1][k];
			}
			if(m >= 0){
				dp[i][m] += dp[i-1][k];
			}
		} 
	}
	
	cout << dp[n-1][num[n]];
	

	return 0;
}

