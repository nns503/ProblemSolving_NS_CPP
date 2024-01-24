#include <bits/stdc++.h>

using namespace std;

int n, l, r, x;
vector<int> arr;
int answer;

void func(int st, int en, int sum){
    for(int i=en+1; i<n; i++){
    	int temp = sum + arr[i];
    	func(st, i, temp); 
    	if(arr[i] - arr[st] < x) continue;
        if(temp >= l && temp <= r) answer++;   
    }
    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r >> x;

    for(int i=0; i<n; i++){
        int a; cin >> a; 
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
	
	for(int i=0; i<n; i++){
		func(i, i, arr[i]);
	}

    cout << answer;

    return 0;
}