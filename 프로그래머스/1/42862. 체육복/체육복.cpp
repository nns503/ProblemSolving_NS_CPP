#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> arr(n+2, 1);
    for(auto student : lost){
        arr[student]--;
    }
    for(auto student : reserve){
        arr[student]++;
    }
    
    for(int i=1; i<=n; i++){
        if(arr[i] == 0){
            if(arr[i-1] >= 2){
                arr[i-1]--;
                arr[i]++;
            }
            else if(arr[i+1] >= 2){
                arr[i+1]--;
                arr[i]++;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(arr[i] >= 1) answer++;
    }
    
    return answer;
}