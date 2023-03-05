#include <bits/stdc++.h>

using namespace std;

int n, answer;
int pos = 52;
int neg = -1;
int one = 0;
int nums[51];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	sort(nums, nums+n);
	
	for(int i=0; i<n; i++){
		if(nums[i]<=0){
			neg = i;
		}
		if(nums[i]==1) one++;
		if(nums[i]>1){
			pos = i;
			break;
		}
	}
	
	for(int cur=n-1; cur>=pos; cur-=2){
		if(cur-1<pos){
			answer += nums[cur];
			break;
		}
		answer += nums[cur]*nums[cur-1];
	}
	
	for(int cur=0; cur<=neg; cur+=2){
		if(cur+1>neg){
			answer += nums[cur];
			break;
		}
		answer += nums[cur]*nums[cur+1];
	}
	
	
	cout << answer+one;
	return 0;
}