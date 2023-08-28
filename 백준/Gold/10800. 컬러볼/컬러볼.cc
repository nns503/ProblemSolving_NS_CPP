#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n;
vector<pair<pair<int, int>, int>> arr;
int num[200001];
int answer[200001];
int sum;
int prv;
int main(void){
	
	cin >> n;
	for(int i=0; i<n; i++){
		int c, s;
		cin >> c >> s;
		arr.push_back({{s, c}, i});
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=1; i<n; i++){
		auto cur = arr[i];
		if(arr[prv].Y.Y != cur.Y.Y){
			for(int k = prv; k<i; k++){
				num[arr[k].Y.X] += arr[k].Y.Y;
				sum += arr[k].Y.Y;
			}
			prv = i;
		}
		answer[cur.X] = sum - num[cur.Y.X];
	}
		

	
	for(int i=0; i<n; i++){
		cout << answer[i] << '\n';
	}	
	return 0;
}
