#include <iostream>
#include <cmath>
#include <algorithm>

int main(void){
	using namespace std;
	
	int n; // 수의 개수
	
	cin >> n;
	
	int num[n];
 
	for(int i=0;i<n;i++){
		cin >> num[i];
	}

	sort(num,num+n);
	
	// 산술 평균	
	double sum=0;
	double avg=0;
	for(int i=0;i<n;i++){
		sum+=num[i];
	}
	avg = round(sum/n);
	
	if(avg==-0){
		avg=0;
	}
	
	cout << avg << endl;
	
	// 중앙값 
	
	cout << num[n/2] << endl;
	
	// 최빈값 
	
	// 처음 3연속일때 오류  11122 
	int mode_num = num[0];
	int mode = 1; 
	int maxmode = 1;
	int samecheck = 0;
	
	for(int i=1;i<n;i++){
		
		if(num[i] == num[i-1]){
			mode++;	
		}
		else{
			mode = 1;
		}
		
		
		if(maxmode == mode&&samecheck==0){
			samecheck++;
			mode_num = num[i];
		}
		else if(maxmode < mode){
			samecheck = 0;
			maxmode = mode; 
			mode_num = num[i];
		}
	}
	
	cout << mode_num << endl;
	
	// 범위   
	int rge = 0;
	rge = num[n-1]-num[0];
	cout << rge << endl;
	  
	return 0;
}
