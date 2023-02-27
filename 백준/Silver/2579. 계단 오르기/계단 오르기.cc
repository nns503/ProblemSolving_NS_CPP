#include <bits/stdc++.h>

using namespace std;

int n;
int dp[301][2];
int step[301];

int solution(int n, int cnt){
	if(dp[n][cnt]!=-1) return dp[n][cnt];
	
	if(cnt == 0)
		dp[n][0] = max(solution(n-2, 1), solution(n-2, 0)) + step[n];
	else
		dp[n][1] = solution(n-1, 0) + step[n]; 
	
	return dp[n][cnt];
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> step[i];
	}
	
	fill(&dp[0][0], &dp[0][0]+301*2, -1);
	if(n==1){
		cout << step[1]; 
		return 0;
	}
	dp[1][0] = step[1];
	dp[1][1] = 0;
	dp[2][0] = step[2];
	dp[2][1] = dp[1][0] + step[2];
	cout << max(solution(n, 0), solution(n, 1));
	return 0;
}
