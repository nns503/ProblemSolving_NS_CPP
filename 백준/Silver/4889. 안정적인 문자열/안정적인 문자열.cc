#include <bits/stdc++.h>

using namespace std;

string s;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 0;
	while(++t){
		int answer = 0;
		stack<char> stk;
		cin >> s;
		if(s[0] == '-') return 0;		
		
		for(int i=0; i<s.size(); i++){
			if(s[i] == '{'){
				stk.push('{');	
			}
			else if(s[i] == '}'){
				if(stk.empty()){
					answer++;
					stk.push('{');
				}
				else{
					stk.pop();
				}
			}
		}
		answer += stk.size() / 2;
		cout << t << ". " << answer << '\n';
		
	}	
}