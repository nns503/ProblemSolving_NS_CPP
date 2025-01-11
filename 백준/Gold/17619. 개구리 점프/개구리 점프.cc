#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin>> n >> q;
    vector<tuple<int, int, int>> arr;
    for(int i=0; i<n; i++){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        arr.push_back({x1, x2, i+1});
    }
    sort(arr.begin(), arr.end());
    vector<int> num(n+1, -1);
    int index = 0;
    int en = 0;
    for(int i=0; i<arr.size(); i++){
        int x1, x2, number;
        tie(x1, x2, number) = arr[i];
        if(x1 > en){
            index++;
        }
        en = max(en, x2);
        num[number] = index;
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (num[a] == num[b]) << '\n';
    }
    return 0;
}