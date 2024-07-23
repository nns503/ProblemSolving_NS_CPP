#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int answer = 0;
    int sum = 0;
    cin >> n;

    vector<int> arr(n);
    for(auto &cur : arr){
        cin >> cur;
        sum += cur;
    }

    sort(arr.begin(), arr.end());
    
    
    if(arr[n-1] <= (sum+1)/2) answer = (sum+1)/2;
    else{
        answer = arr[n-1];
    }


    cout << ((answer >= 1441) ? -1 : answer);
    return 0;
}