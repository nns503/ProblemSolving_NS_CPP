#include <bits/stdc++.h>

using namespace std;

string dp[251];

string cacl(string s1, string s2){
	int sum = 0;
	string temp;
	while(!s1.empty() || !s2.empty() || sum){
		if(!s1.empty()){
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if(!s2.empty()){
			sum += s2.back() - '0';
			s2.pop_back();
		}
		temp.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

int main(void){
	ios::sync_with_stdio(0);
	
	dp[0] = "1";
	dp[1] = "1";
	for(int i = 2; i<=250; i++){
		dp[i] = cacl(cacl(dp[i-2], dp[i-2]), dp[i-1]);
	}
	
	int n;
		while(true){
		cin >> n;
		if(cin.eof()) break;
		cout << dp[n] << '\n'; 
	}
	return 0;
}