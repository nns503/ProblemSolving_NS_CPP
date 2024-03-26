#include <bits/stdc++.h>

using namespace std;

int n, answer;
bool vis[10];

int getSum(vector<int> &a){
    int sum = 0;
    for(int i=0; i<n-1; i++){
        sum += abs(a[i] - a[i+1]);
    }
    return sum;
}

void func(vector<int> &a, vector<int> &arr, int cnt){
    if(cnt == n){ 
        int temp = getSum(a);
        if(answer < temp){
            answer = temp;
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        a[cnt] = arr[i];
        vis[i] = true;
        func(a, arr, cnt+1);
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i;
    }
    vector<int> a(n);
    func(a, arr, 0);
    cout << answer;
    return 0;
}