#include <bits/stdc++.h>

using namespace std;

int m, n, l;
int answer;

int getDist(int x, int a, int b){
    return (abs(x - a) + b);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> l;

    vector<int> arr(m);
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int a, b, find;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        int st = 0, en = m-1;

        while(st<=en){
            int mid = (st+en)/2;
            if(getDist(arr[mid], a, b) <= l){
                answer++;
                break;
            }
            else if(arr[mid] < a){
                st = mid+1;
            }
            else en = mid-1;
        }
    }
    

    cout << answer;
    return 0;
}
