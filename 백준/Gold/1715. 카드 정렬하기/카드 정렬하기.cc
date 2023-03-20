#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int f = n;
	while(n--){
		int a;
		cin >> a;
		pq.push(a);
	}
	
	int sum = 0;
	while(pq.size() != 1){
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		sum += temp;
		pq.push(temp);
	}
	
	cout << sum;
		
	return 0;
}

