#include <bits/stdc++.h>

using namespace std;

bool answer;
string s, t;

void func(string a){
	if(s.size() == a.size()){
		if(s == a) answer = true;
		return;
	}
	
	string temp = a;
	if(temp.back() == 'A'){
		temp.pop_back();
		func(temp);
	}
	if(a.front() == 'B'){
		reverse(a.begin(), a.end());
		a.pop_back();
		func(a);
	} 
}

int main(void){
	cin >> s;
	cin >> t;
	
	func(t);
	cout << answer;
	return 0;
}