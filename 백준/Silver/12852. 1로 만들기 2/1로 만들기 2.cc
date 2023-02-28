#include <bits/stdc++.h>

using namespace std;

int x;
int dp[1000001];
int root[1000001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x;
	dp[1] = 0;
	root[1] = 0;
	
	for(int i = 2; i <= x; i++){
		dp[i] = dp[i-1] + 1;
		root[i] = i-1;
		if(i%3==0) {
			if(dp[i] > dp[i/3] + 1){
				dp[i] = dp[i/3] + 1;
				root[i] = i/3;
			}
		}
		if(i%2==0) {
			if(dp[i] > dp[i/2] + 1){
				dp[i] = dp[i/2] + 1;
				root[i] = i/2;
			}			
		}
	}
	
	cout << dp[x] << '\n' ;
	
	while(x!=0){
		cout << x << ' ';
		x = root[x];
	}
	
	return 0;
}