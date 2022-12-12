	#include <iostream>
	#include <algorithm>
	#include <cmath>	
	#include <string>
	#include <climits>
	
	using namespace std;
	
	int dp[15][15];
	int solve(int k,int n){
		if(k==0) return n;
		if(n==1) return 1;
		if(dp[k][n]!=-1) return dp[k][n];
		dp[k][n] = solve(k,n-1)+solve(k-1,n);
		return dp[k][n];
	}
	
	int main(void){
		int k,n;
		int num;
		cin >> num;
		fill(dp[0],dp[15],-1);
		for(int i = 0; i<num;i++){
			cin >> k >> n;
			cout << solve(k,n) << "\n";
		}
	}
