#include <bits/stdc++.h>

using namespace std;

string s;
bool chk;

void func(int p){
	if(p >= s.size()){
		chk = true;
		return;
	}
	
	if(s[p] == '1'){
		p++;
		int z = 0; int o = 0;
		while(p < s.size() && s[p] == '0'){
			if(z >= 2) func(p);
			p++;
			z++;
		}
		if(z < 2) return;
		while(p < s.size() && s[p] == '1'){
			if(o >= 1) func(p);
			p++;
			o++;
		}
		if(o < 1) return;
		func(p);	
	}
	else if(s[p] == '0'){
		p++;
		if(p >= s.size()) return;
		if(s[p] != '1') return;
		func(p+1);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> s;
	
	func(0);
	
	cout << (chk?"SUBMARINE":"NOISE");
	
	return 0;
}