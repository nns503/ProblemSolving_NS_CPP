#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> arr(6);
    int t, p;

    cin >> n;
    for(auto &cur : arr) cin >> cur;
    cin >> t >> p;

    int tshirt = 0;
    for(int i=0; i<6; i++){
        tshirt += (arr[i] + (t - 1)) / t;
    }

    int pen = 0, one = 0;
    pen = n / p;
    one = n % p;
    
    cout << tshirt << '\n';
    cout << pen << ' ' << one;   
    return 0;
}