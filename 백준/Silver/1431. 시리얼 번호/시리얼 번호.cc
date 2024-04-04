#include <bits/stdc++.h>

using namespace std;

int getNum(char &c){
    if(c >= '0' && c <= '9') return c - '0';
    else return 0; 
}

int sumNum(string &arr){
    int sum = 0;
    for(auto cur : arr){
        sum += getNum(cur);
    }

    return sum;
}

bool cmp(string &arr1, string &arr2){
    if(arr1.size() == arr2.size()){
        int sum1 = sumNum(arr1);
        int sum2 = sumNum(arr2);
        if(sumNum(arr1) == sumNum(arr2)){
            return arr1 < arr2;
        }
        return sumNum(arr1) < sumNum(arr2);            
    

    }
    return arr1.size() < arr2.size();
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    sort(arr.begin(), arr.begin()+n, cmp);

    for(auto cur : arr) cout << cur << '\n';
    return 0;
}