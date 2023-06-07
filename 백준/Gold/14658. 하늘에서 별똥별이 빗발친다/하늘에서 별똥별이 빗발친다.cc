#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, l, k;
int answer = 101;
vector<pair<int, int>> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> l >> k;
	
	int t = k;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		arr.push_back({a, b});
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<k; i++){
		int temp = 0;
		int j = i + 1;
		vector<int> y;
		y.push_back(arr[i].Y);
		while(abs(arr[i].X - arr[j]. X) <= l && j < k){
			y.push_back(arr[j].Y);
			j++;
		} 
		sort(y.begin(), y.end());
		int en = 0;
		for(int st=0; st<y.size(); st++){
			while(y[en] - y[st] <= l && en < y.size()){
				en++;
			}
			temp = max(en - st, temp);
		}
		answer = min(k - temp, answer);
	} 
	
	cout << answer;
	return 0;
}