#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 1;
	long long l, p, v;
	long long answer = 0;
	
	while(true){
		cin >> l >> p >> v;
		if(l==0 && p==0 && v==0) break;
		answer = v/p*l;
		if(l>v%p) answer += v%p;
		else answer += l;
		cout << "Case " << cnt << ": " << answer << '\n';
		cnt++;
	}
	
	return 0;
}