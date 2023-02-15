#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char> w;
	string s;
	int stick = 0;
	cin >> s;
	w.push(s[0]);
	for(int i=1;i<s.size();i++){
		if(s[i]=='('){
			w.push(s[i]);
		}
		else{ //a==')'
			if(s[i-1]=='('){
				w.pop();
				stick += w.size();
			}
			else{
				w.pop();
				stick++;
			} 
		}
	}
	
	cout << stick;
	
	return 0;
}