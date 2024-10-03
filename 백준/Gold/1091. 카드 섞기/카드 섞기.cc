#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> p(n);
    vector<int> s(n);
    set<string> vis;
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) arr[i] = i;
    int answer = 0;
    while(true){
        bool flag = false;
        string str;
        for(int i=0; i<n; i++){
            int cur = arr[i];
            if(p[cur] != i % 3){
                flag = true;                
            }
            str += to_string(cur);
        }
        if(vis.find(str) == vis.end()){
            vis.insert(str);
        }
        else{
            break;
        }

        if(!flag){
            cout << answer;
            return 0;
        }
        
        vector<int> temp = arr;
        for(int i=0; i<n; i++){
            arr[s[i]] = temp[i];
        }

        answer++;
    }

    cout << -1;
    return 0;
}