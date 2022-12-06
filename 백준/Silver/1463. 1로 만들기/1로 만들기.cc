#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#define MAX 1000005

using namespace std;

int dp[MAX];

int solution(int x){
	int temp = 0;
	
	if(x==1) return 0;
	if(x==2) return 1;
	if(x==3) return 1;
	
	if(dp[x-1]==-1){
		dp[x] = solution(x-1)+1;
	}
	else{
		dp[x] = dp[x-1] + 1;
	}
	
	if(x%2==0) {
		if(dp[x/2]==-1){
			temp = solution(x/2)+1;
		}
		else{
			temp = dp[x/2]+1;
		}
		if(temp<dp[x]) dp[x] = temp;
	}
	if(x%3==0){
		if(dp[x/3]==-1){
			temp = solution(x/3)+1;
		}
		else{
			temp = dp[x/3]+1;
		}		
		if(temp<dp[x]) dp[x] = temp;
	}
	
	return dp[x];
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	fill_n(dp,n,-1);
	cout << solution(n);
	
	return 0;
}

