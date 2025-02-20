#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;
    if(arr.size() <= 1){
        cout << "A";
        return 0;
    }
    int s = abs(abs(arr[0]) - abs(arr[1]));

    set<int> answer;
    for(int a=-1000; a<=1000; a++){
        bool flag = true;
        int prv = arr[0];
        int b = arr[1] - prv * a;
        for(int i=1; i<n; i++){
            if(arr[i] != prv * a + b){
                flag = false;
                break;
            }
            prv = arr[i];
        }
        if(flag){
            answer.insert(arr.back() * a + b);
        }
    }

    if(answer.empty()){
        cout << 'B';
    }
    else if(answer.size() >= 2){
        cout << 'A';
    }
    else{
        for(auto cur : answer) cout << cur;
    }

    return 0;
}