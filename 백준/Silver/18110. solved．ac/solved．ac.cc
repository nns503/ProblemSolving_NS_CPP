#include <bits/stdc++.h>

using namespace std;

int n, mod, sum, answer;
vector<int> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    if(n == 0){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    double d = (double) n * 15 / 100;
    if(d + 0.5 >= ceil(d)) mod = (int) ceil(d);
    else mod = (int) d;
    
    sort(arr.begin(), arr.end());

    for(int i = mod; i<n-mod; i++){
        int a; cin >> a;
        sum += arr[i];
    }
    double temp = (double) sum / (double)(n - mod * 2);
    if(temp + 0.5 >= ceil(temp)) answer = (int) ceil(temp);
    else answer = (int) temp;     
    
    cout << answer;
}