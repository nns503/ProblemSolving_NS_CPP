#include <bits/stdc++.h>

using namespace std;

string s;
bool chk;
int a[27];
string answer;
string temp;
int main(void){
	
	cin >> s;
	
	for(int i=0; i<s.size(); i++){
		a[s[i] - 'A']++;
	}

	
	for(int i=0; i<26; i++){
		if(a[i] == 0) continue;
		if(a[i] % 2 == 1){
			if(!chk){
				chk = true;
				temp.push_back('A' + i);
			}
			else{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
		for(int j=0; j<a[i]/2; j++){
			answer.push_back('A' + i);
		}
	}
	
	s = answer;
	reverse(s.begin(), s.end());
	if(chk) answer = answer + temp + s;
	else answer = answer + s;
	
	cout << answer;
	
	return 0;
}