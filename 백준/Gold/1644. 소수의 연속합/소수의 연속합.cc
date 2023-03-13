#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v; 
bool pn[4000001];

void prime(int n){
	for(int i=2; i<=n; i++){
		if(!pn[i]){
			v.push_back(i); 
			for(int j=i+i; j<=n; j+=i){
				pn[j] = true;
			}
		}
	}
}

int main(void){
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	prime(n);
	int cnt = 0;
	int len = v.size();
	int en = 0;
	int sum = v[0];
	for(int st=0; st<len; st++){
		while(en < len && sum < n){
			en++;
			if(en==v.size()) break;
			sum += v[en];			
		}
		if(sum == n) cnt++;
		sum -= v[st];
	}
	cout << cnt;
	return 0;
}