#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        
        sort(str.begin(), str.end());

        do{
            cout << str << '\n';
        }while(next_permutation(str.begin(), str.end()));
    }
    return 0;
}