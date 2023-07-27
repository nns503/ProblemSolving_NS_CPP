#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[1000001];

int find(int x){
	if(num[x] == x) return x;	
	return num[x] = find(num[x]);
}

void uni(int x, int y){
	int a = find(x);
	int b = find(y);
	
	if(a > b) num[a] = b;
	else num[b] = a;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;	
	
	for(int i=0; i<=n; i++){
		num[i] = i;
	}
	
	while(m--){
		int a, b, c;
		
		cin >> a >> b >> c;
		
		if(a == 0){
			uni(b, c);
		}
		else if(a == 1){
			if(find(b) == find(c)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}