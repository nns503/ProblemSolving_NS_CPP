#include <bits/stdc++.h>

using namespace std;

int asclen[1001];
int desclen[1001];
int n, a;
vector<int> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;   

    for(int i=0; i<n; i++){
        cin >> a;
        arr.push_back(a);
    }

    vector<int> ascArr;
    asclen[0] = 1; ascArr.push_back(arr[0]);

    for(int i=1; i<n; i++){
        int cur = arr[i];
        if(ascArr.back() < cur){
            ascArr.push_back(cur);
            asclen[i] = asclen[i-1] + 1;
        }
        else{
            int index = lower_bound(ascArr.begin(), ascArr.end(), cur) - ascArr.begin();
            ascArr[index] = cur;
            asclen[i] = asclen[i-1];
        }
    }

    vector<int> descArr;
    desclen[n-1] = 1; descArr.push_back(arr[n-1]);
    
    for(int i=n-2; i>=0; i--){
        int cur = arr[i];
        if(descArr.back() < cur){
            descArr.push_back(cur);
            desclen[i] = desclen[i+1] + 1;
        }
        else{
            int index = lower_bound(descArr.begin(), descArr.end(), cur) - descArr.begin();
            descArr[index] = cur;
            desclen[i] = desclen[i+1];
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        answer = max(answer, desclen[i] + asclen[i] - 1);
    }
    cout << answer;
    return 0;
}