#include <bits/stdc++.h>

using namespace std;


int n, k;
int rk[1001];
int md[1001][3];
int a[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=1; i<=n; i++){
		cin >> a[i] >> md[i][0] >> md[i][1] >> md[i][2];
		rk[i] = 1;
		for(int j=1; j<i; j++){
			if(md[a[i]][0] < md[a[j]][0]){
				rk[i]++;
			}
			else if(md[a[i]][0] > md[a[j]][0]){
				rk[j]++;
			}
			else{
				if(md[a[i]][1] < md[a[j]][1]){
					rk[i]++;
				}
				else if(md[a[i]][1] > md[a[j]][1]){
					rk[j]++;
				}	
				else{
					if(md[a[i]][2] < md[a[j]][2]){
						rk[i]++;
					}
					else if(md[a[i]][2] > md[a[j]][2]){
						rk[j]++;
					}	
				}
			} 
		}
	}
	
	cout << rk[k];
	return 0;
}