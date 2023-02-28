#include <bits/stdc++.h>

using namespace std;

int n;
int dp[501][502];
int num[501][502];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++) cin >> num[i][j];
	}
	
	dp[1][1] = num[1][1];
	
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j];
		}
	}

	int result = 0;
	
	for(int i=1; i<=n; i++){
		result = max(result, dp[n][i]);
	}
	cout << result;	
	
	return 0;
}

