#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    string str;
    string target = to_string(n);

    for(int i=1; i<=n; i++){
        str.append(to_string(i));
    }

    for(int i=0; i<str.size()-target.size()+1; i++){
        if(target == str.substr(i, target.size())){
            cout << i+1;
            return 0;
        }
    }
    return 0;
}