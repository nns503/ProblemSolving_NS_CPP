#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>	

using namespace std;

int main(void){
	using namespace std;
	
	int n;  

	cin >> n; 

	int arr[n+1]; // 목표 수열 
	int st[n+1]; // 스택 
	int p=1; // 목표 수열 번호 
	int s=0; // 스택 번호 
	char text[n*2];
	int c=0;
	
	// 목표 수열 입력  
	for(int i=1;i<n+1;i++){
		cin >> arr[i];
	}
	
	for(int i=1;i<n+1;i++){
		st[s+1]=i;
		s++;
		text[c]='+';
		c++;
		
		while(1){
			if(s!=0&&st[s]==arr[p]){
				text[c]='-';
				c++;
				s--;
				p++;
			}
			else break;
		}		
	}
	
	if(s==0){
		for(int i=0;i<n*2;i++){
			cout << text[i] << "\n";
		}
	}
	else{
		cout << "NO";
	}
	
	return 0;
}
