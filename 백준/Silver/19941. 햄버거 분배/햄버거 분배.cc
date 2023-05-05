#include <bits/stdc++.h>

using namespace std;

queue<int> h;
queue<int> p;
int n, k;
int answer;

int main(void){
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		char c;
		cin >> c;
		if(c == 'H') h.push(i);
		if(c == 'P') p.push(i);
	}
	
	while(!h.empty() && !p.empty()){
		int nh = h.front();
		int np = p.front(); 
		if(nh < np && nh >= np-k){
			p.pop();
			h.pop();
			answer++;
		}
		else if(np < nh && np >= nh-k){
			p.pop();
			h.pop();
			answer++;
		}
		else if(nh < np) h.pop();
		else if(np < nh) p.pop();
	}
	
	cout << answer;
	
	return 0;
}