#include <bits/stdc++.h>

using namespace std;

int T, k;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		cin >> k;
		multiset<int> s;
		while(k--){
			char c;
			int n;
			cin >> c >> n;
			if(c == 'I'){
				s.insert(n);
			}
			else if(c == 'D' && !s.empty()){
				if(n == 1) {
					s.erase(prev(s.end()));
				}
				else s.erase(s.begin());
			}
		}
		s.empty()?(cout<<"EMPTY\n"):(cout<<*prev(s.end())<<' '<<*s.begin()<<'\n');
	}
	return 0;
}