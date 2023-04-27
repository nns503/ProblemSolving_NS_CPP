#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[2001];
bool dp[2001][2001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		dp[i][i] = true;
	}
	
	for(int i=1; i<n; i++){
		if(arr[i] == arr[i+1]) dp[i][i+1] = true;
	}
	
	for(int i=2; i<n; i++){
		for(int j=1; j<=n-i; j++){
			if(arr[j] != arr[j+i]) continue;
			if(dp[j+1][j+i-1]) dp[j][j+i] = true;
		}
	}	
	
	cin >> m;
	
	while(m--){
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
    
	return 0;
}