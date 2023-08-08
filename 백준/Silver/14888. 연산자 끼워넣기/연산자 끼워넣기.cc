#include <bits/stdc++.h>

using namespace std;

int n, a;
vector<int> op;
vector<int> num;
bool chk[12];
int mx = -0x3f3f3f3f;
int mn = 0x3f3f3f3f;

void func(int cnt, int sum){
	if(cnt == n){
		mx = max(sum, mx);
		mn = min(sum, mn);
		return ;
	}
	
	for(int i=0; i<n-1; i++){
		if(chk[i]) continue;
		int cur = sum;
		if(op[i] == 0) cur += num[cnt];
		else if(op[i] == 1) cur -= num[cnt];
		else if(op[i] == 2) cur *= num[cnt];
		else if(op[i] == 3) cur /= num[cnt];
		chk[i] = true;
		func(cnt+1, cur);
		chk[i] = false;
	}
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a; num.push_back(a);
	}

	for(int i=0; i<4; i++){
		cin >> a;
		while(a--){
			op.push_back(i);
		}
	}

	func(1, num[0]);
	
	cout << mx << '\n' << mn;
	
	return 0;
}