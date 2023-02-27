#include <bits/stdc++.h>

using namespace std;

int T;
int n,m;

bool cmp(int a, int b){
	return a > b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		int answer = 0;
		cin >> n >> m;
		vector<int> a;
		vector<int> b;
		while(n--){
			int q;
			cin >> q;
			a.push_back(q);
		}
		while(m--){
			int q;
			cin >> q;
			b.push_back(q);
		}
		sort(a.begin(), a.end(), cmp);		
		sort(b.begin(), b.end());
		
		for(int i=0; i<a.size(); i++){
			for(int j=0; j<b.size(); j++){
				if(a[i]>b[j]) answer++;
				else break;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}