#include <bits/stdc++.h>

using namespace std;

stack<int> stk;
int n, h;
long long answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	stk.push(0x3f3f3f3f);
	
	for(int i=1; i<=n; i++){
		cin >> h;
		
		while(stk.top() <= h){
			stk.pop();
		}
		
		stk.push(h);
		answer += (stk.size() - 2);
	}

	cout << answer;
	
	return 0;
}

