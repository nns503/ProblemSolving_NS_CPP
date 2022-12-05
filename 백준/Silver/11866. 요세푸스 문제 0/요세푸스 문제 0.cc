#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#define MAX 10050

using namespace std;

int uporder(int order, int* data, int n);

int main(){
	int n,k; // N명의 사람과, K번째 마다 죽는 수 
	int death=0; // 죽은 사람의 수 
	int order=0; // 현재 순서
	int count=0;  
	cin >> n >> k;
	
	int data[n+1];
	int jose[n+1];
	
	for(int i=1;i<n+1;i++){
		data[i]=i;
	}
	
	while(death<n){
		count++;
		order = uporder(order,data,n);
		if(count%k==0){
			jose[death+1]=order;
			data[order]=0;
			death++;
		}
	} 
	
	cout << "<";
	for(int i=1;i<n;i++){
		cout << jose[i] << ", ";
	}
	cout << jose[n] << ">";
	
	return 0;
}

int uporder(int order, int* data, int n){
	do{
		if(order==n){
		order=0;
	}	
		order++;
	}while(data[order]==0);
	
	return order;
}
	

