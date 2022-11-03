#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;


int main(void){
	using namespace std;
	
	int n;
	int cip = 0;
	int num[10];
	int t = 0;
	bool check = true;
	while(true){
		cin >> n;
		if(n==0) break;
		
		while(n>0){
			cip++;
			num[cip] = n%10;
			n /= 10;
		}
		
		t = cip;
		if(cip%2==0){
			for(int i=1;i<=cip/2;i++){
				if(num[i]!=num[t]) {
					check = false;
				}
				else t--;
			}
		}
		else{
			for(int i=1;i<=cip/2;i++){
				if(num[i]!=num[t]) {
					check = false;
				}
				else t--;
			}			
		}
		
		(check)?cout << "yes\n":cout << "no\n";
		
		check = true;
		cip = 0;
	}

	return 0;
}

