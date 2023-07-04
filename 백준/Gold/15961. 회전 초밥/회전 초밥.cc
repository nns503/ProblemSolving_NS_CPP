#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, d, k, c;
int vis[3001];
int pos = 0;
int st = 0;
int cnt;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d >> k >> c;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	for(int i=0; i<k; i++){
		arr.push_back(arr[i]);
	}
	vis[c]++; cnt++;
	
	while(pos < arr.size()){
		int cur = arr[pos];
		int s = arr[st];
		if(pos < k){
			if(vis[cur] == 0) cnt++;
			vis[cur]++;
			pos++;
		}
		else{
			if(s != c){
				vis[s]--;
				if(vis[s] == 0) cnt--;
			}
			if(cur != c){
				vis[cur]++;
				if(vis[cur] == 1) cnt++;	
			}
			pos++;
			st++;
		}
		answer = max(answer, cnt);	
	}
	
	cout << answer;
	return 0;
}