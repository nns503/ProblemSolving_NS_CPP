#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<>> pq;
vector<pair<long long, long long>> v;
int n;
long long ramen;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
	if(a.first == b.first) a.second > b.second;
	return a.first < b.first;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		long long a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto a : v){
		if(pq.size() < a.first){
			pq.push(a.second);
		}
		else if(pq.size() == a.first){
			if(pq.top() < a.second){
				pq.pop();
				pq.push(a.second);
			}
		}
	}
	
	while(!pq.empty()){
		ramen += pq.top();
		pq.pop();
	}
	
	cout << ramen;
	return 0;
}