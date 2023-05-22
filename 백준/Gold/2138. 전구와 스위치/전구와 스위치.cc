#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string init;
string target;
int answer = 10000000;

void func(int cnt, int bt){
	if(cnt == n-1){
		if(s[cnt-1] != target[cnt-1] && s[cnt] != target[cnt]) answer = min(answer, bt+1);
		else if(s[cnt-1] == target[cnt-1] && s[cnt] == target[cnt]) answer = min(answer, bt);
		return ;
	}
	
	if(s[cnt-1] == target[cnt-1]) func(cnt+1, bt);
	else{
		for(int i=-1; i<=1; i++){
			if(s[cnt+i] == '0'){
				s[cnt+i] = '1';
			}
			else s[cnt+i] = '0';
		}
		func(cnt+1, bt+1);
	}
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> init >> target;
	s = init;
	func(1, 0);
	s = init;
	for(int i=0; i<2; i++){
		if(s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
	func(1, 1);
	cout << (answer == 10000000 ? -1 : answer);
	
	return 0;
}



