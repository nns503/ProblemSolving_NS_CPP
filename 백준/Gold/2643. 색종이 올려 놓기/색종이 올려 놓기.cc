#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
vector<pair<int, int>> arr;
int num[101];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), greater<>());
    
    num[0] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i].X <= arr[j].X && arr[i].Y <= arr[j].Y && num[j] > num[i]){
                num[i] = num[j];                
            }
        }
        num[i]++;
    }

    cout << *max_element(num, num+n);

    return 0;
}

