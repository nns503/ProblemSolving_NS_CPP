#include <bits/stdc++.h>

using namespace std;

int n;
int a[100001][3];
int mx[3];
int mn[3];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		mx[i] = a[1][i];
		mn[i] = a[1][i];
	}
	
	for(int i=2; i<=n; i++){
		int temp[3];
		temp[0] = a[i][0] + max(mx[0], mx[1]);
		temp[1] = a[i][1] + max(mx[0], max(mx[1], mx[2]));
		temp[2] = a[i][2] + max(mx[1], mx[2]);
		
		for(int j=0; j<3; j++){
			mx[j] = temp[j];	
		}
		
		temp[0] = a[i][0] + min(mn[0], mn[1]);
		temp[1] = a[i][1] + min(mn[0], min(mn[1], mn[2]));
		temp[2] = a[i][2] + min(mn[1], mn[2]);
		
		for(int j=0; j<3; j++){
			mn[j] = temp[j];	
		}
	}	
	
	cout << *max_element(mx, mx+3) << ' ' << *min_element(mn, mn+3);

	return 0;
}