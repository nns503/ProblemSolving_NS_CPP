#include <bits/stdc++.h>

using namespace std;

int T;

int main(void){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> T;
	cin.ignore();
	while(T--){
		unordered_set<string> m;
		string s, a, temp;
		getline(cin, s);
		int pos = 0;

		while(true){
			getline(cin, a);
			if(a == "what does the fox say?") break;
				
			pos = 0;
			int cnt = 0;
			while(pos < a.size()){
				int nxt = a.find(' ', pos);
				if(nxt == -1) nxt = a.size();
				if(nxt - pos > 0 && cnt == 2){
					m.insert(a.substr(pos, nxt - pos));
				}	
				pos = nxt + 1;	
				cnt++;				
			}
		}
		
		pos = 0;
		while(pos < s.size()){
			int nxt = s.find(' ', pos);
			if(nxt == -1) nxt = s.size();
			if(nxt - pos > 0){
				if(m.find(s.substr(pos, nxt - pos)) == m.end()){
					cout << s.substr(pos, nxt - pos) << ' ';
				}
			}
			pos = nxt + 1;					
		}
	}	
	return 0;
}