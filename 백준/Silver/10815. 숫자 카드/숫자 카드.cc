#include <bits/stdc++.h>

using namespace std;

int n, m;
int card[500001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> card[i];
	}
	sort(card, card+n);
	
	cin >> m;
	while(m--){
		int a;
		cin >> a;
		cout << binary_search(card, card+n, a) << ' ';
	}
	
	return 0;
}