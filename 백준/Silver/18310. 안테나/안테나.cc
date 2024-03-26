#include <bits/stdc++.h>

using namespace std;

int n;

long getDist(vector<int> &arr, int p){
    long sum = 0;
    for(int i=0; i<n; i++){
        sum += abs(arr[p] - arr[i]);
    }
    return sum;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    int number;
    for(auto &i : arr){
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    if(n == 1 || n == 2) cout << arr[0];
    else{
        
        int mid = n/2;
        long p1 = getDist(arr, mid-1);
        long p2 = getDist(arr, mid);
        long p3 = getDist(arr, mid+1);
        if(p1 <= p2){
            if(p1 <= p3) number = mid-1;
            else number = mid+1;
        }
        else{
            if(p2 <= p3) number = mid;
            else number = mid+1;
        }
        cout << arr[number];
    }

    return 0;
}