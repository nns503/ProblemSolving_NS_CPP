#include <bits/stdc++.h>

using namespace std;

int n, s;
int num[100001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	int en = 0;
	int sum = num[0];
	int answer = 0x7fffffff;
	for(int st=0; st<n; st++){
		while(en<n && sum<s){
			en++;
			if(en != n) sum += num[en];
			
		}
		if(en==n) break;
		answer = min(en-st+1, answer);
		sum -= num[st];
	}
	cout << ((answer==0x7fffffff)?0:answer);
	return 0;
}
