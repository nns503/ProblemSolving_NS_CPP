#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> asc(100001, 1);
vector<int> desc(100001, 1);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);        
    }

    asc[0] = 1; desc[0] = 1;

    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1]){
            asc[i] = asc[i-1] + 1;
        }

        if(arr[i] <= arr[i-1]){
            desc[i] = desc[i-1] + 1;
        }
    }
    
    int as = *max_element(asc.begin(), asc.begin() + n);
    int ds = *max_element(desc.begin(), desc.begin() + n);
    cout << max(as, ds);

    return 0;
}