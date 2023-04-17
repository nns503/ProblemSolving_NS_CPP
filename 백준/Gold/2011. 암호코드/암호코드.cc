#include <bits/stdc++.h>

using namespace std;

string s;
int cur;
int prv = 0;
long long dp[5001][2];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	dp[0][1] = 1;
	for(int i=1; i<=s.size(); i++){
		cur = s[i-1] - '0';
		if(cur == 0 && prv == 0){
			cout << 0;
			return 0;
		}
		if(i != s.size() && s[i] == '0'){
			if(cur >= 3){
				cout << 0;
				return 0;
			}
			dp[i+1][1] += dp[i-1][0] % 1000000;
			dp[i+1][1] += dp[i-1][1] % 1000000;
			i++;
			prv = 0;
		}
		else{
			dp[i][0] += dp[i-1][1];
			if(prv == 1 || (prv == 2 && cur <= 6)){
				dp[i][0] += dp[i-1][0] % 1000000;
				dp[i][1] += dp[i-1][0] % 1000000;
			}
			else{
				dp[i][0] += dp[i-1][0] % 1000000;
			}
			prv = cur;
		}
	} 
	cout << (dp[s.size()][0] + dp[s.size()][1]) % 1000000;
	return 0;
}
