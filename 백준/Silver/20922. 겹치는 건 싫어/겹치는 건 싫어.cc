#include <bits/stdc++.h>

using namespace std;

int n, k;
int num[200001];
int arr[200001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int answer = 0;
	int en = 0;
	for(int st=0; st<n; st++){
		while(en < n && num[arr[en]] < k){
			num[arr[en]]++;
			en++;
		}
		answer = max(answer, en - st);
		num[arr[st]]--;
	}
	
	cout << answer;
	return 0;
}