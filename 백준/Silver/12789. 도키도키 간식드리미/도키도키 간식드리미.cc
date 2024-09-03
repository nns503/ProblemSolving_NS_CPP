#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;

    stack<int> stk;
    stk.push(-1);
    int index = 1;
    for(int i=0; i<n; i++){
        auto cur = arr[i];
        if(cur == index){
            index++;
        }
        else{
            stk.push(cur);
        }
        while(index == stk.top()){
            stk.pop();
            index++;
        }

    }

    if(stk.top() == -1) cout << "Nice";
    else cout << "Sad";
    return 0;
}