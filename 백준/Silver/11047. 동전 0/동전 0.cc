#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>	

using namespace std;

int main(void){
	using namespace std;
	
	int n,k, sum=0;
	
	cin >> n >> k;
	
	int amount[n+1];
	
	for(int i=1;i<n+1;i++){
		cin >> amount[i];
	}
	
	for(int i=n;i>0;i--){
		sum += k/amount[i];
		k %= amount[i];	
	}
	
	cout << sum;
	return 0;
}
