#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int T;
int n, m;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		
		cin >> n >> m;
		
		for(int i=0; i<m ;i++){
			int a, b;
			cin >> a >> b;
		}
		
		cout << n-1 << '\n';
	
	}	
	
	return 0;
}