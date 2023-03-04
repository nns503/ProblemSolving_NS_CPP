#include <bits/stdc++.h>

using namespace std;

int a[51];
int b[51];
int n;

int main(void){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n; i++){
		cin >> b[i];
	}
	
	sort(a, a+n);
	sort(b, b+n, greater<int>());
	
	int answer = 0;
	for(int i=0; i<n; i++){
		answer += a[i]*b[i];
	}
	
	cout << answer;
	return 0;
}