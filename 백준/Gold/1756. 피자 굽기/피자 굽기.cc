#include <bits/stdc++.h>

using namespace std;

int d, n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> d >> n;
    vector<int> arr(d+1, 0x3f3f3f3f);

    for(int i=1; i<=d; i++){
        cin >> arr[i];
        if(arr[i-1] < arr[i]) arr[i] = arr[i-1];
    }
    
    int p = d;
    for(int i=0; i<n; i++){
        int cur; 
        cin >> cur;

        while(p > 0){
            if(arr[p] >= cur){
                arr[p] = 0;
                break;
            }
            else{
                p--;
            }
        }

        if(p <= 0){
            break;
        }
    }

    cout << p;
    return 0;
}