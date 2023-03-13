#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[10001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	int cnt = 0;
	int en = 0;
	int sum = num[0];
	
	for(int st=0; st<n; st++){
		while(en<n && sum < m){
			en++;
			if(en == n) break;
			sum += num[en];
		}
		if(sum == m) cnt++;
		sum -= num[st];
	}
	
	cout << cnt;
	return 0;
}