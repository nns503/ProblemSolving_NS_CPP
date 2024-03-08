#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll T;
int n, m;
ll answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    vector<ll> A, B;
    vector<ll> arrA, arrB;
    cin >> n;

    for(int i=0; i<n; i++){
        ll a; cin >> a;
        A.push_back(a);
    }

    for(int i=0; i<n; i++){
        ll sumA = 0;
        for(int j=i; j<n; j++){
            sumA += A[j];
            arrA.push_back(sumA);
        }
    }
    sort(arrA.begin(), arrA.end());

    cin >> m;
    for(int i=0; i<m; i++){
        ll b; cin >> b;
        B.push_back(b);
    }

    for(int i=0; i<m; i++){
        ll sumB = 0;
        for(int j=i; j<m; j++){
            sumB += B[j];
            arrB.push_back(sumB);
        }
    }
    sort(arrB.begin(), arrB.end());

    for(int i=0; i<arrA.size(); i++){
        if(binary_search(arrB.begin(), arrB.end(), T - arrA[i])){
            answer += upper_bound(arrB.begin(), arrB.end(), T - arrA[i]) - lower_bound(arrB.begin(), arrB.end(), T - arrA[i]);
        }
    }

    cout << answer;
    return 0;
}
