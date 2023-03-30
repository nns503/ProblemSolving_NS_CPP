#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v[501];
bool vis[501];
int answer = 0;


int main(void){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	vis[1] = true;
	for(auto a : v[1]){
		if(!vis[a]) answer++;		
		vis[a] = true;
		for(auto b : v[a]){
			if(!vis[b]) answer++;
			vis[b] = true;
		}
	}
	cout << answer;
	return 0;
}