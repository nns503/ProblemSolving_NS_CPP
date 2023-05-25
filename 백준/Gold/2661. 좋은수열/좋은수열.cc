#include <bits/stdc++.h>

using namespace std;

int n;
bool en = false;
void func(string s){
	if(s.size() == n){
		cout << s;
		en = true;
		return ;
	}
	for(int i=1; i<=3; i++){
		if(en) return;
		bool chk = true;
		s.push_back(i + '0');
		for(int k=1; k<=s.size()/2; k++){
			if(s.substr(s.size()-k, k) == s.substr(s.size()-k*2, k)){
				chk = false;
				break;
			}
		}
		if(chk) func(s);
		s.pop_back();
	}
}

int main(void){
	
	cin >> n;
	func("1");
	return 0;
}