	#include <iostream>
	#include <algorithm>
	#include <vector>
	
	using namespace std;

	long long tree(vector<long long> data, int n, int mid){
		long long int sum = 0;
		for(int i=0;i<n;i++){
			if(data[i]-mid>0)
			sum += data[i]-mid;
		}
		return sum;
	}
	
	long long int binary_search(vector<long long> data, int n, int target){
		long long high = data[n-1];
		long long low = 0;
		long long mid;
		while(high>=low){
			mid = (high+low)/2;
			if(target>tree(data,n,mid)){
				high = mid-1;
			}
			else if(target<=tree(data,n,mid)){
				low = mid+1;
			}
		}	
		
		return high;
	}
	
	
	int main(void){
		
		int n,target;
		vector<long long> data;
		cin >> n >> target;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			data.push_back(a);
		}
		
		sort(data.begin(),data.end());
		
		
		cout << binary_search(data,n,target);
		
		return 0;
}
		