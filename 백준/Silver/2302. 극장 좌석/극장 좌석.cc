#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[41];
int pb[41];
bool vip[41]; 
int cnt = 0;
int answer = 1;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	while(m--){
		int a;
		cin >> a;
		vip[a] = true;
	}
	pb[0] = 1;
	pb[1] = 1;
	for(int i=2; i<=40; i++){
		pb[i] = pb[i-2] + pb[i-1];
	}
	
	vector<int> sum;
	for(int i=1; i<=n; i++){
		if(!vip[i]){
			cnt++;
		}
		else{
			sum.push_back(pb[cnt]);
			cnt = 0;
		}
	}

	sum.push_back(pb[cnt]);
	
	
	for(int nxt : sum){
		answer *= nxt;
	}
	
	cout << answer;
	return 0;
}



