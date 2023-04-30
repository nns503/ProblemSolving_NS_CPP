#include <bits/stdc++.h>

using namespace std;

int arr[3];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		cin >> arr[0] >> arr[1] >> arr[2];
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
		sort(arr, arr+3);
		if(arr[2] >= arr[1] + arr[0]) cout << "Invalid\n";
		else if(arr[2] == arr[1] && arr[1] == arr[0]) cout << "Equilateral\n";
		else if(arr[2] == arr[1] || arr[1] == arr[0]) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
	return 0;
}