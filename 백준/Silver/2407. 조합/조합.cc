#include <bits/stdc++.h>

using namespace std;


string dp[101][101];
string s = "1";
int n, m;

string cul(string s1, string s2){
	string sum;
	int temp = 0;
	while(!s1.empty() || !s2.empty() || temp != 0){
		if(!s1.empty()){
			temp += s1.back() - '0';
			s1.pop_back();
		}
		
		if(!s2.empty()){
			temp += s2.back() - '0';
			s2.pop_back();
		}	
		
		sum.push_back((temp % 10) + '0');
		temp /= 10;
	} 	
	
	reverse(sum.begin(), sum.end());
	return sum;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=0; i<=100; i++){
		dp[i][0] = "1";
	}
	
	for(int i=1; i<=100; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = cul(dp[i-1][j-1], dp[i-1][j]);
		}
	}
	
	cout << dp[n][m];
	return 0;
}



