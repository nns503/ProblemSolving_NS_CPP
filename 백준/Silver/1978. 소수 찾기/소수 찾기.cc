#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

void eratos(int *sieve, int n);

int sieve[1001]={};

int main(void){
	
	int n=0;
	int count = 0;
	int compare;
	
	cin >> n;
	
	eratos(sieve,1000);
	
	for(int i=0;i<n;i++){
		cin >> compare;
		if(sieve[compare]!=0) count++;
	}
	
	cout << count;
	
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
