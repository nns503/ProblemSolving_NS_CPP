#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr;
    map<int, string> title;
    for(int i=0; i<n; i++){
        string str;
        int num;
        cin >> str >> num;
        if(title.find(num) != title.end()) continue;
        arr.push_back(num);
        title[num] = str;
    }

    sort(arr.begin(), arr.end());
    
    while(m--){
        int a;
        cin >> a;
        cout << title[*lower_bound(arr.begin(), arr.end(), a)] << '\n';
    }

    return 0;
}