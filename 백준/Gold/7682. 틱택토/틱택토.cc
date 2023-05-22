#include <bits/stdc++.h>

using namespace std;

string s;

bool ttt(char c){
	// 가로 검사 
	for(int i=0; i<9; i+=3){
		if(s[i] == c && s[i+1] == c && s[i+2] == c){
			return true; 
		}
	}
	
	// 세로 검사
	for(int i=0; i<3; i++){
		if(s[i] == c && s[i+3] == c && s[i+6] == c){
			return true;
		}
	} 
	
	//대각선 검사 
	if(s[0] == c && s[4] == c && s[8] == c){
		return true;
	}
	
	if(s[2] == c && s[4] == c && s[6] == c){
		return true;
	}
	
	return false;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		cin >> s;
		if(s == "end") return 0;
		
		int o = 0;
		int x = 0;
		bool co = ttt('O');
		bool cx = ttt('X');
		for(char c : s){
			if(c == 'X') x++;
			else if(c == 'O') o++;
		}
		
		if(x - o > 1 || x - o < 0){
			cout << "invalid\n";
			continue;
		}
		else if((co && cx) || (o + x != 9 && !co && !cx)){
			cout << "invalid\n";
			continue;
		}
		else if((x == o && cx) || (x-1 == o && co)){
			cout << "invalid\n";
			continue;
		}
		cout << "valid\n";
	}
}