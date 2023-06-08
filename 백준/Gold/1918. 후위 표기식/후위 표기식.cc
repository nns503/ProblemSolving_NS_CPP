#include <bits/stdc++.h>

using namespace std;

string s, answer;
stack<char> op;

void func(char c){
	if(c == '+' || c == '-'){
		while(!op.empty() && op.top() != '('){
			answer.push_back(op.top()); op.pop();
		}
		op.push(c);
	}
	else if(c == '*' || c == '/'){
		while(!op.empty() && (op.top() == '*' || op.top() == '/')){
			answer.push_back(op.top()); op.pop();
		}
		op.push(c);
	}
}
int main(void){
	
	cin >> s;

	for(char c : s){
		if(c >= 'A' && c <= 'Z'){
			answer.push_back(c);
		} 
		else{
			if(c == '(') op.push(c);
			else if(c == ')'){
				while(!op.empty() & op.top() != '('){
					answer.push_back(op.top()); op.pop();
				}
				op.pop();
			}
			else func(c);
		}
	}
	while(!op.empty()){
		answer.push_back(op.top()); op.pop();
	}
	cout << answer;
	return 0;
}