#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int d[500001];
int answer;
vector<pair<int, int>> p;

int find(int x){
	if(d[x] == x) return x;
	else return d[x] = find(d[x]);	
}

bool uni(int x, int y){
	x = find(x);
	y = find(y);
	if(x > y) swap(x,y);
	if(x == y) return true;
	else{
		d[y] = x;
		return false;
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		d[i] = i;
	}
	
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		p.push_back({x, y});
	}	
	
	for(int i=0; i<p.size(); i++){
		auto cur = p[i];
		bool chk = uni(cur.X, cur.Y);
		if(chk){
			answer = i + 1;
			break;
		}
	}
	
	cout << answer;
	
	return 0;
}