#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cable_search(vector<long long> cable,int k, int mid){
	int sum = 0;
	for(int i=0;i<k;i++){
		sum += (cable[i]/mid);
	}
	return sum;
}

int binary_search(vector<long long> cable, int k, int target){
	long long high = cable[k-1];
	long long low = 1;
	long long mid;
	while(high>=low){
		mid = (high+low)/2;
		int sum = cable_search(cable,k,mid);
		if(sum<target){
			high = mid - 1;
		}
		else if(sum>=target){
			low = mid + 1;
		}
	}
	return high;
}

int main(void){
	int k,n;
	cin >> k >> n;
	vector<long long> cable;
	
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		cable.push_back(a);
	}
	
	sort(cable.begin(),cable.end());
	
	cout << binary_search(cable,k,n);
	
}