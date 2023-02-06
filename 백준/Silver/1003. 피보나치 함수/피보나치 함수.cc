#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[42];

int fibo(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(dp[n]!=-1) return dp[n];
	dp[n] = fibo(n-1)+fibo(n-2);
	return dp[n];
}

int main(void){
	int t;
	cin >> t;
	fill(&dp[0],&dp[42],-1);
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		if(n==0){
			cout << "1 0\n";
			continue;
		}
		cout << fibo(n-1) << " " << fibo(n) << "\n";
	}
	return 0;
}