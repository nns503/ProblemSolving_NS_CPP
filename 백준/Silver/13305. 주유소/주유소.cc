#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> len;
vector<int> oil;
int mn = 0x7f7f7f7f;
long long answer;

int main(void){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int a;
		cin >> a;
		len.push_back(a);
	}
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		oil.push_back(a);
	}
	
	for(int i=0; i<n-1; i++){
		mn = min(mn, oil[i]);
		answer += len[i] * mn; 
	}
	
	cout << answer;
	return 0;
}
