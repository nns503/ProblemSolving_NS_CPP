#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		if(i % 2 == 1){
			pq1.push(a);
		}
		else{
			pq2.push(a);
		}
		if(i!=1 && pq1.top()>pq2.top()){
			pq1.push(pq2.top());
			pq2.push(pq1.top());
			pq1.pop();
			pq2.pop();
		}
		cout << pq1.top() << '\n';
	}
	return 0;
}