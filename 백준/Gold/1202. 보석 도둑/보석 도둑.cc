#include <bits/stdc++.h>
#define M first
#define V second

using namespace std;

int n, k, c;
vector<pair<int, int>> gem;
multiset<int> bag;

bool cmp(pair<int, int> v1, pair<int, int> v2){
	if(v1.V == v2.V){
		return v1.M < v2.M;
	}
	return v1.V > v2.V;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		gem.push_back({a, b});
	}
	
	for(int i=0; i<k; i++){
		int a;
		cin >> a;
		bag.insert(a);
	}
	sort(gem.begin(), gem.end(), cmp);
	
	int cnt = 0;
	long long money = 0;
	for(auto g : gem){
		if(bag.empty()) break;
		if(cnt == k) break;
		auto it = bag.lower_bound(g.M);
		if(it!=bag.end()){
			cnt++;
			money += g.V;
			bag.erase(it);
		}
		
	}
	cout << money;
	
	return 0;
}