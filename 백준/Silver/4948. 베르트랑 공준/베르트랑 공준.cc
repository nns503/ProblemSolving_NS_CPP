#include <bits/stdc++.h>

using namespace std;

bool vis[300000]; 
int dp[300000]; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=2; i<=123456*2; i++){
		dp[i] = dp[i-1];
		if(vis[i]) continue;
		dp[i]++;
		for(int j=i; j<=123456*2; j+=i){
			vis[j] = true;
		}
	}
	
	while(true){
		int n;
		cin >> n;
		if(n == 0) return 0;
		cout << dp[2*n] - dp[n] << '\n';
	}	

}