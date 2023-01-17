#include <iostream>
#include <string>
#include <deque>

using namespace std;

long long int dp[101];
long long int solution(int x){
	if(x==1||x==2||x==3) return 1;
	if(x==4||x==5) return 2;
	if(dp[x]!=0) return dp[x];
	dp[x] = solution(x-1)+solution(x-5);
	return dp[x];
}

int main(void){
	int n;
	cin >> n;
	fill_n(dp,101,0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		cout << solution(x) << "\n";
	}
	return 0;
}