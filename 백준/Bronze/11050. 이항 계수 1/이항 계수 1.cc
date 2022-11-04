#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

int main(void){
	using namespace std;
	
	int n,k;
	cin >> n >> k;	
	int result = n;
	
	if(k==0) result=1;
	for(int i=1;i<k;i++){
		result = result * (n-i) / (i+1);
	}
	
	cout << result;
	return 0;
}

