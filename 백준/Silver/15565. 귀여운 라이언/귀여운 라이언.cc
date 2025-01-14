#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr[i] = a;
    }

    int st = 0;
    int en = 0;
    int answer = 0x3f3f3f3f;    
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 1) cnt++;
        if(cnt == k){
            en = i;
            while(arr[st] != 1){
                st++;
            }
            answer = en - st + 1;
            break;
        }
    }

    if(answer == 0x3f3f3f3f){
        cout << -1;
        return 0;
    }

    while(en < n){
        en++;
        if(arr[en] == 1){
            st++;
            while(arr[st] != 1){
                st++;
            }
            answer = min(answer, en - st + 1);
        }
    }

    cout << answer;

    return 0;
}