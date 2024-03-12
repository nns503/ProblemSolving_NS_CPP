#include <bits/stdc++.h>

using namespace std;

const int CP = 101;
int n;
int arr[101];
int vis[101];
int answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++){
        if(vis[i] != 0) continue;
        vis[i] = i;
        int cur = arr[i];
        while(true){
            if(vis[cur] == i){
                vis[cur] = CP;
                cur = arr[cur];
                answer++;
            }
            else if(vis[cur] == 0){
                vis[cur] = i;
                cur = arr[cur];
            }
            else break;
        }
    }

    cout << answer << '\n';

    for(int i=1; i<=n; i++){
        if(vis[i] == CP) cout << i << '\n';
    }
    return 0;
}