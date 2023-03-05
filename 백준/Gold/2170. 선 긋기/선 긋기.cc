#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

long long answer = 0;
long long s, e;
bool cmp(pair<long long, long long> a, pair<long long, long long> b){
	if(a.Y == b.Y){
		return a.X < b.X;
	}
	return a.Y < b.Y;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<pair<long long, long long>> v;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	s = v[0].X;
	e = v[0].Y;
	
	for(int i=1; i<n; i++){
		if(e>v[i].X){
			e = max(v[i].Y,e);
		}
		else{
			answer += abs(e-s);
			s = v[i].X;
			e = v[i].Y;
		}
	} 
	answer += abs(e-s);
	cout << answer;
		
	return 0;
}