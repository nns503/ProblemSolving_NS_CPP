#include <bits/stdc++.h>
#define X first
#define Y second 

using namespace std;

int n, k, answer;
int cnt[101];
vector<int> e[101];
vector<int> nxt[101];
vector<int> arr; // n번째, 아이템이름ㅇ 
vector<pair<int, int>> s;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=0; i<k; i++){
		int a;
		cin >> a;
		arr.push_back(a);
		e[a].push_back(i);
	}
	
	for(int i=0; i<arr.size(); i++){
		if(e[arr[i]].empty()) continue;
		if(e[arr[i]].size() == nxt[arr[i]].size()+1){
			nxt[arr[i]].push_back(10000);
		} 
		else nxt[arr[i]].push_back(e[arr[i]][nxt[arr[i]].size()+1]);
	}
	
	for(auto cur : arr){
		bool chk = false;
		if(s.size() < n){
			for(int i=0; i<s.size(); i++){
				if(s[i].Y == cur){
					s[i].X = nxt[cur][cnt[cur]]; cnt[cur]++;
					chk = true;
					break;
				}
			}		
			if(chk) continue;	
			s.push_back({nxt[cur][cnt[cur]], cur});
			cnt[cur]++;
		}
		else{
			sort(s.begin(), s.end());
			for(int i=0; i<s.size(); i++){
				if(s[i].Y == cur){
					s[i].X = nxt[cur][cnt[cur]]; cnt[cur]++;
					chk = true;
					break;
				}
			}
			if(chk) continue;
			s[s.size()-1] = {nxt[cur][cnt[cur]], cur};
			cnt[cur]++;
			answer++;
		}
	}
	
	cout << answer;
	return 0;
}