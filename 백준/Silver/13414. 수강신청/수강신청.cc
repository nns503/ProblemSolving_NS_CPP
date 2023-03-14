#include <bits/stdc++.h>

using namespace std;

int K, L;
unordered_map<string, int> m;

bool cmp(pair<string, int> a1, pair<string, int> a2){
	return a1.second < a2.second;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> K >> L;
	for(int i=0; i<L; i++){
		string a;
		cin >> a;
		m[a] = i;
	}
	
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	K = min(K, (int)v.size());
	for(int i=0; i<K; i++){
		cout << v[i].first << '\n';
	}
	return 0;
}