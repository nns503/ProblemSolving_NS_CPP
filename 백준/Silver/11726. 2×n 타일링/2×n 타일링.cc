#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;

int dp[1001];

int solution(int x){
	if(x==1) return 1;
	if(x==2) return 2;
	if(dp[x]!=-1) return dp[x];
	dp[x] = (solution(x-1)+solution(x-2))%10007;
	return dp[x];
}

int main(void){
	
	int n;
	cin >> n;
	fill_n(dp,1001,-1);
	cout << solution(n);
	
	
	return 0;
}
