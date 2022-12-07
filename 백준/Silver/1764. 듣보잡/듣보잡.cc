#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;

bool binary_search(string* data, int m, string target);

int main(void){
	int n,m,size;
	cin >> n >> m;
	if(n>m) size=n; else size=m;
	string hear[n];
	string see[m]; 
	string no[size];
	int count = 0;
	
	for(int i=0;i<n;i++){
		cin >> hear[i];
	}
	
	for(int i=0;i<m;i++){
		cin >> see[i];
	}
	
	sort(hear,hear+n);
	sort(see,see+m);
	
	for(int i=0;i<n;i++){
		if(binary_search(see,m,hear[i])==true){
			no[count]=hear[i];
			count++;
		}
	}
	
	cout << count << "\n";
	for(int i=0;i<count;i++){
		cout << no[i] << "\n";
	}
	return 0;
}

bool binary_search(string* data, int m, string target){
	int high = m-1;
	int low = 0;
	int mid;
	while(low<=high){
		mid = (high+low)/2;
		if(target == data[mid]) return true;
		else if(target < data[mid]) high = mid-1;
		else if(target > data[mid]) low = mid+1;
	}
	return false;
}
 
