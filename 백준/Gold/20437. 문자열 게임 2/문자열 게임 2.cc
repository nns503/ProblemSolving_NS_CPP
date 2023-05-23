#include <bits/stdc++.h>

using namespace std;

int t;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--){
		vector<int> alp[26];
		string w; int k;
		int mx = -1;
		int mn = 10001;
		bool chk = false;
		cin >> w;
		cin >> k;
		for(int i=0; i<w.size(); i++){
			int c = (w[i] - 'a');	
			alp[c].push_back(i);
		}
		for(int i=0; i<26; i++){
			int cnt = 0;
			while(alp[i].size() - cnt >= k){
				mx = max(mx, alp[i][cnt+k-1] - alp[i][cnt] + 1);
				mn = min(mn, alp[i][cnt+k-1] - alp[i][cnt] + 1);
				cnt++;
			}
		}
		if(mx == -1) cout << -1 << '\n';
		else cout << mn << ' ' << mx << '\n';
	}
	return 0;
}