#include <bits/stdc++.h>

using namespace std;

int rc[100001];
int lc[100001];
int n;
int cnt = 1;
int answer;
bool chk;

void func(int cur, int le){
	if(lc[cur] != -1){
		cnt++;
		answer++;
		func(lc[cur], le + 1);
		answer++;
	}
	if(rc[cur] != -1){
		cnt++;
		answer++;
		func(rc[cur], le);
		answer++;
		if(le == 0){
			answer --;
		}
	}
}

int main(void){
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
	}
	
	func(1, 0);
	cout << answer;
	
	return 0;
}