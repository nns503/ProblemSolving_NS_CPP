#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int cnt = n*n;
	while(cnt--){
		int a;
		cin >> a;
		if(pq.size() < n) pq.push(a);
		else{
			if(pq.top()<a){
				pq.pop();
				pq.push(a);
			}
		}
	}
	
	cout << pq.top();
	return 0;
}