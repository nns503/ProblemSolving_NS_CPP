#include <bits/stdc++.h>

using namespace std;

string s[13];
string b;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	s[0] = "-";
	b = " ";	
	for(int i=1; i<=12; i++){
		if(i > 1){
			string temp = b;
			for(int k=0; k<2; k++){
				b += temp;
			}
		}
		s[i] = s[i-1] + b + s[i-1];	
	}
	
	while(true){
		int n;
		cin >> n;
		if(cin.eof()) return 0; 
		cout << s[n] << '\n';
	}
}