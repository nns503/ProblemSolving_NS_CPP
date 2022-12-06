#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>


using namespace std;

bool binary_search(int* data, int n, int target);

int main(){
	int n, m;
	
	cin >> n;
	int data[n];
	for(int i=0;i<n;i++){
		cin >> data[i];
	}
	
	cin >> m;
	int compare[m];
	for(int i=0;i<m;i++){
		cin >> compare[i];
	}
	
	sort(data,data+n);
	
	
	int high, low, mid;
	
	for(int i=0;i<m;i++){
		cout << binary_search(data,n,compare[i]) << "\n";
	}
	return 0;
}

bool binary_search(int* data, int n, int target){
	int high = n-1;
	int low = 0;
	while(low <= high){
		int mid = (high+low)/2;
		
		if(target == data[mid]) return true;
		else if(target < data[mid]){
			high = mid-1;
		}
		else if(target > data[mid]){
			low = mid+1;
		}
	}
	return false;
}

