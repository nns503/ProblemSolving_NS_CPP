#include <bits/stdc++.h>

using namespace std;

int n;
int num[1001];
int b[1001];
int len[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> num[i];
	}
	
	fill(len+1, len+1+n, 1);
	
	b[1] = 1;
	for(int i=2; i<=n; i++){
		b[i] = i;
		for(int j=1; j<i; j++){
			if(num[i] > num[j]){
				if(len[i] < len[j]+1){
					len[i] = len[j]+1;
					b[i] = j;
				}
			}
		}
	}
	
	int m = 0;
	int mb = 0;
	for(int i=1; i<=n; i++){
		if(m < len[i]){
			m = len[i];
			mb = i;
		} 
	}
	
	stack<int> s;
	s.push(mb);
	while(b[s.top()]!=s.top()){
		s.push(b[s.top()]);
	}
	
	cout << m << '\n';
	while(!s.empty()){
		cout << num[s.top()] << ' ';
		s.pop();
	}	
	return 0;
}