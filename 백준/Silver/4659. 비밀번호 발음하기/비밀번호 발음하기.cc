#include <bits/stdc++.h>

using namespace std;

string s;

void text(bool a){
	if(a) cout << "<" << s << "> is acceptable.\n";
	else cout << "<" << s << "> is not acceptable.\n"; 
}

bool isV(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		int v = 0;
		int c = 0;
		bool chk = false;
		char prev = ' ';
		cin >> s;
		if(s == "end") return 0;
		
		for(int i=0; i<s.size(); i++){
			if(s[i] != 'o' && s[i] != 'e' && prev == s[i]){
				chk = false;
				break;
			}
			else prev= s[i]; 
			
			if(isV(s[i])){
				c = 0;
				chk = true;
				v++; 
			}
			else{
				v = 0;
				c++;
			}
			if(c == 3 || v == 3){
				chk = false;
				break;
			}
		}
		text(chk);
	}
}