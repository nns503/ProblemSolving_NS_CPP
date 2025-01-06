#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    cin >> n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    set<int> s;
    s.insert(arr[0]);
    for(int i=1; i<n; i++){
        vector<int> temp;
        temp.push_back(arr[i]);
        for(auto cur : s){
            temp.push_back(cur + arr[i]);
        }
        for(auto cur : temp){
            s.insert(cur);
        }
    }
    
    int num = 1;
    while(s.find(num) != s.end()){
        num++;
    }
    cout << num;
}