#include <bits/stdc++.h>

using namespace std;

int n;
string s1, s2;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin.ignore();
	getline(cin, s1, '*');
	getline(cin, s2);
	while(n--){
		string a;
		cin >> a;
		if(a.size() < s1.size() + s2.size()) cout << "NE\n"; 
		else if(s1 == a.substr(0, s1.size()) && s2 == a.substr(a.size()-s2.size(), s2.size())){
			cout << "DA\n";
			
		}
		else cout << "NE\n"; 
	}
	
	
	return 0;
}