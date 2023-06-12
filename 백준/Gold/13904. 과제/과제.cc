#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, answer;
int s[1001];
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.X == b.X) return a.Y > b.Y;
	return a.X < b.X;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	int t = n;
	while(t--){
		int d, w;
		cin >> d >> w;
		arr.push_back({d, w});
	}	
	
	sort(arr.begin(), arr.end(), cmp);

	for(auto cur :  arr){
		if(pq.size() < cur.X){
			pq.push(cur.Y);
		}
		else{
			if(pq.top() < cur.Y){
				pq.pop();
				pq.push(cur.Y);
			}
		}
	}
	
	while(!pq.empty()){
		answer += pq.top();
		pq.pop();
	}
	
	cout << answer;
	return 0;
}