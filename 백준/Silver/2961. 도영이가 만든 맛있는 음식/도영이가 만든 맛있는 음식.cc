#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;
vector<pair<int, int>> arr;
int answer = 0x3f3f3f3f;

void solve(int index, int z, int x){
    if(index == arr.size()){
        answer = min(answer, abs(z - x));
        return ;
    }

    solve(index+1, z * arr[index].A, x + arr[index].B);
    solve(index+1, z, x);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    for(int i=0; i<arr.size(); i++){
        solve(i+1, arr[i].A, arr[i].B);
    }

    cout << answer;

    return 0;
}