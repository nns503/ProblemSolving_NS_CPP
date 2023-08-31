#include <bits/stdc++.h>

using namespace std;

int n, p;
int answer;
stack<int> s[7];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		
		while(!s[a].empty() && s[a].top() > b){
			s[a].pop();
			answer++;
		}
		
		if(s[a].empty() || s[a].top() != b){
			answer++;
			s[a].push(b);
			
		}
	}
	
	cout << answer;
	return 0;
}

