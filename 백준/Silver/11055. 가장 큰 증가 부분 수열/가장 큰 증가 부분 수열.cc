#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
pair<int ,int> nums[1001];


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> nums[i].X;
	}
	
	nums[1].Y = nums[1].X;
	
	for(int i=2; i<=n; i++){
		for(int j=i-1; j>=1; j--){
			if(nums[i].X > nums[j].X)
				nums[i].Y = max(nums[j].Y, nums[i].Y);
		}
		nums[i].Y += nums[i].X;
	}
	
	int result = 0;
	for(int i=1; i<=n; i++){
		result = max(result, nums[i].Y);
	}
	cout << result;
	
	return 0;
}