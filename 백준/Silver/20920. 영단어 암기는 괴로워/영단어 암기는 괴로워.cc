#include <bits/stdc++.h>

using namespace std;

int n, x;

bool cmp(pair<int, string> a, pair<int, string> b){

    if(a.first == b.first){
        if(a.second.size() == b.second.size()){
            return a.second < b.second;
        }
        return a.second.size() > b.second.size();
    }
    return a.first > b.first;
}

int main(void){
    cin >> n >> x;
    map<string, int> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(str.size() < x) continue;
        m[str]++;
    }
    vector<pair<int, string>> arr;
    for(auto cur : m){
        arr.push_back({cur.second, cur.first});
    }

    sort(arr.begin(), arr.end(), cmp);
    for(auto cur : arr){
        cout << cur.second << '\n';
    }
}

