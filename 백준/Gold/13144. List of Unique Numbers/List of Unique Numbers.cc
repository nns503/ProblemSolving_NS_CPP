#include <bits/stdc++.h>

using namespace std;

int n, en;
set<int> s;
int num[100001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	long long cnt = 0;
	s.insert(num[0]);
	
	for(int st=0; st<n; st++){
		while(en<n && s.find(num[en+1])==s.end()){
			en++;
			if(en == n) break;
			s.insert(num[en]);
		}
		cnt += s.size(); 
		s.erase(num[st]);
	}
	
	cout << cnt; 
	
	return 0;
}