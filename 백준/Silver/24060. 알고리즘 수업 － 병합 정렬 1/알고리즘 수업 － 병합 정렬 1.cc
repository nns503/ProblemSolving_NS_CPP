#include <bits/stdc++.h>

using namespace std;

int n, k;
int id = 0;
int answer = -1;
vector<int> arr;

void startMerge(int p, int q, int r){
    int i = p;
    int j = q+1;
    int t = 1;
    int temp[r+2];
    while(i <= q && j <= r){
        if(arr[i] <= arr[j]){
            temp[t++] = arr[i++];
        }
        else{
            temp[t++] = arr[j++];
        }
    }
    while(i <= q){
        temp[t++] = arr[i++];
    }
    while(j <= r){
        temp[t++] = arr[j++];
    }
    i = p;
    t = 1;
    while(i <= r){
        arr[i] = temp[t];
        id++;
        if(id == k){
            answer = arr[i];
        }
        i++;
        t++;
    }
}

void merge_sort(int p, int r){
    if(p < r){
        int q = ((p+r) / 2);
        merge_sort(p, q);
        merge_sort(q+1, r);
        startMerge(p, q, r);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    arr.resize(n+1);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    merge_sort(0, n-1);

    cout << answer;
}