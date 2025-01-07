#include <bits/stdc++.h>

using namespace std;

int n, q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    vector<bool> vis(n+1, false);
    
    int num;
    for(int i=0; i<q; i++){
        cin >> num;
        int temp = num;
        int answer = 0;
        while(temp > 0){
            if(vis[temp]) answer = temp;  
            temp /= 2;
        }
        if(answer == 0) vis[num] = true;
        cout << answer << '\n';
    }
    return 0;
}