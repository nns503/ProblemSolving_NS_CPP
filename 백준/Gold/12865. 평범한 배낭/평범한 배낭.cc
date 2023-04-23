#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k;
pair<int, int> j[101];
int dp[101][100001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int w, v;
		cin >> w >> v;
		j[i] = {w, v};
	}	
	
	for(int i=1; i<=n; i++){
		for(int w=1; w<=k; w++){
			if(j[i].X > w) dp[i][w] = dp[i-1][w];
			else dp[i][w] = max(dp[i-1][w-j[i].X] + j[i].Y, dp[i-1][w]);
		}
	}
	
	cout << dp[n][k];
	return 0;
}