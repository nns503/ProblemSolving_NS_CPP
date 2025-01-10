#include <bits/stdc++.h>
#define END first
#define LEN second
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> arr;

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end(), greater<>());
    int en = arr[0].END;

    for(auto cur : arr){
        en = min(en, cur.END);
        en -= cur.LEN;
    }

    cout << en;

    
    return 0;
}