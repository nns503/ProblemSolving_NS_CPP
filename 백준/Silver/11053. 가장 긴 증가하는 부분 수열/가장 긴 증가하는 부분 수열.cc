#include <bits/stdc++.h>

using namespace std;

int n;
int num[1001];
int len[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> num[i];
	}
	
	fill(len+1, len+1+n, 1);
	
	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++){
			if(num[i] > num[j]){
				len[i] = max(len[i], len[j]+1); 
			}
		}
	}
	
	cout << *max_element(len+1, len+n+1);
		
	return 0;
}