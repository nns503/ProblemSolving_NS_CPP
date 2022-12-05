#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

void eratos(int *sieve, int n);

int sieve[1000100]={};

int main(void){
	using namespace std;
	int m,n;
	
	cin >> m >> n;
	
	eratos(sieve, n);
	
	for(int i=m;i<=n;i++){
		if(sieve[i]!=0) cout << sieve[i] << "\n" ;
	}
	
	return 0;
}

void eratos(int *sieve, int n){
	for(int i=2;i<=n;i++){
		sieve[i] = i;
	}
	
	for(int i=2;i<=n;i++){
		if(sieve[i]==0) continue;
		
		for(int j=i+i;j<=n; j+=i){
			sieve[j] = 0;
		}
	}
}