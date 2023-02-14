#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	/*
	2
<<BP<A>>Cd-
ThIsIsS3Cr3t
BAP
	*/
	for(int i=0;i<N;i++){
		string s;
		list<char> L;
		cin >> s;
		auto cursor = L.begin();
		for(int j=0;j<s.size();j++){
			switch(s[j]){
				case '<':
					if(cursor!=L.begin()) cursor--;
					break;
				case '>':
					if(cursor!=L.end()) cursor++;
					break;
				case '-':
					if(cursor!=L.begin()){
						cursor--;
						cursor = L.erase(cursor);
					}
					break;
				default:
					L.insert(cursor,s[j]);
			}
		}
		for(auto a : L) cout << a;
		cout << '\n';
	}
	return 0;
}