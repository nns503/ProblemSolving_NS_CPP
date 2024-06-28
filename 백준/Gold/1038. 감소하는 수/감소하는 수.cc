#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;

void func(long long num, int cur){
    while(cur >= 0){
        long long temp = num * 10;
        temp += cur;
        arr.push_back(temp);
        cur--;
        func(temp, cur);
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    func(0, 9);
    sort(arr.begin(), arr.end());
    if(n >= arr.size()) cout << -1;
    else cout << arr[n];

    return 0;
}

