#include <bits/stdc++.h>

using namespace std;

int n, k;
int num[1000001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> num[i];
	
	int en = 0;
	int del = 0;
	int cnt = 0;
	int answer = 0;
	for(int st = 0; st < n; st++){
		while(en < n && (num[en] % 2 == 0 || del < k)){
			if(num[en] % 2) del++;
			else cnt++;
			en++; 
		} 
		answer = max(answer, cnt);
		if(!(num[st] % 2)) cnt--;
		else if(del > 0 && num[st] % 2) del--;
	}
	
	cout << answer;
	return 0;
}