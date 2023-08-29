#include <bits/stdc++.h>

using namespace std;

string s;
string tx;

bool subP(){
	return (tx.substr(tx.size()-4, 4) == "PPAP");
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	
	for(int i=0; i<s.size(); i++){
		tx.push_back(s[i]);
		if(tx.size() >= 4){
			if(subP()){
				tx.erase(tx.size()-3, 3);
			}
		}
	}
	if(tx == "P") cout << "PPAP";
	else cout << "NP";
	return 0;
}

