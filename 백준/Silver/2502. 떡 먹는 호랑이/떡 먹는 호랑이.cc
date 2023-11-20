#include <bits/stdc++.h>

using namespace std;

int d, k;
int dp[31];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> d >> k;
	
	dp[2] = 1;
	dp[3] = 1;
	
	for(int i=4; i<=30; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	for(int i=1;;i++){
		int a = dp[d-1] * i;
		if((k-a) % dp[d] == 0){
			cout << i << '\n' << (k-a) / dp[d];
			break;
		}	
	}
	return 0;
}