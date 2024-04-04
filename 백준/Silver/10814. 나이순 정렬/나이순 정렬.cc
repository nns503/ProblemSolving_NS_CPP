#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

vector<pair<int, int>> arr(100001);
string name[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i].A;
        cin >> name[i];
        arr[i].B = i;
    }

    sort(arr.begin(), arr.begin() + n);

    for(int i=0; i<n; i++){
        cout << arr[i].A << ' ' << name[arr[i].B] << '\n';
    }
    return 0;
}