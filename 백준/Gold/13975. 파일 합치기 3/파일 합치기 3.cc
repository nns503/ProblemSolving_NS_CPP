#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int T, K;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> K;
		while(K--){
			int a;
			cin >> a;
			pq.push(a);
		}	
		
		long long sum = 0;
		while(pq.size() > 1){
			long long a = pq.top(); 
			pq.pop();
			long long b = pq.top();
			pq.pop();
			sum += (a+b);
			pq.push(a+b);
		}
		cout << sum << '\n';
		pq.pop();
	}
	return 0;
}