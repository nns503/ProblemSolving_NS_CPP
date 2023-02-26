#include <bits/stdc++.h>

using namespace std;

int n;
long long num[100001];
long long answer;
int cnt;
int mx = 0; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	
	answer = num[0];
	cnt = 1;
	
	for(int i=1; i<n; i++){
		if(num[i-1]==num[i]){
			cnt++;
		}
		else{
			cnt = 1;
		}
		
		if(cnt>mx){
			answer = num[i-1];
			mx = cnt;
		}		
	}
	
	cout << answer;
	
	return 0;
}