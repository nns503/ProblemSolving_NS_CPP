#include <iostream>
#include <algorithm>
#include <string>

// compare 재정의
using namespace std;

int main(void){
	using namespace std;
	
	int n,m;
	cin >> n >> m;
	
	int card[n];
	
	for(int i=0;i<n;i++){
		cin >> card[i];
	}
	
	int jack = 0;
	int sum = 0;
	sort(card,card+n);

	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=i+2;k<n;k++){
				sum = card[i]+card[j]+card[k];
				if(m>=sum&&jack<sum){
					jack=sum;
				}
				else if(m<sum){
					break;
				}
			}
		}
	}
	cout << jack;
	return 0;
}
