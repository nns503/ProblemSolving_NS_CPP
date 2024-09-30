#include <bits/stdc++.h>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, p;
    cin >> c >> p;

    vector<int> arr(c+1);

    for(int i=1; i<=c; i++) cin >> arr[i];

    int answer = 0;
    if(p == 1){
        answer += c;
        for(int x=1; x<=c-3; x++){
            if(arr[x] == arr[x+1] && arr[x+1] == arr[x+2] && arr[x+2] == arr[x+3]) answer++;
        }
    }
    else if(p == 2){
        for(int x=1; x<=c-1; x++){
            if(arr[x] == arr[x+1]) answer++;
        }
    }
    else if(p == 3){
        for(int x=1; x<=c-2; x++){
            if(arr[x] == arr[x+1] && arr[x+1] == arr[x+2] - 1) answer++;
        }
        for(int x=1; x<=c-1; x++){
            if(arr[x] - 1 == arr[x+1]) answer++;
        }
    }
    else if(p == 4){
        for(int x=1; x<=c-2; x++){
            if(arr[x] - 1 == arr[x+1] && arr[x+1] == arr[x+2]) answer++;
        }
        for(int x=1; x<=c-1; x++){
            if(arr[x] == arr[x+1] -1) answer++;
        }
    }
    else if(p == 5){
        for(int x=1; x<=c-2; x++){
            if(arr[x] == arr[x+1] && arr[x+1] == arr[x+2]) answer++;
            if(arr[x] - 1 == arr[x+1] && arr[x+1] == arr[x+2] - 1) answer++;
        }
        for(int x=1; x<=c-1; x++){
            if(arr[x] == arr[x+1] - 1) answer++;
            if(arr[x] -1 == arr[x+1]) answer++;
        }
    }
    else if(p == 6){
        for(int x=1; x<=c-2; x++){
            if(arr[x] == arr[x+1] && arr[x+1] == arr[x+2]) answer++;
            if(arr[x] == arr[x+1] - 1 && arr[x+1] == arr[x+2]) answer++;
        }
        for(int x=1; x<=c-1; x++){
            if(arr[x] == arr[x+1]) answer++;
            if(arr[x] - 2 == arr[x+1]) answer++;
        }
    }
    else if(p == 7){
        for(int x=1; x<=c-2; x++){
            if(arr[x] == arr[x+1] && arr[x+1] == arr[x+2]) answer++;
            if(arr[x] == arr[x+1] && arr[x+1] - 1== arr[x+2]) answer++;
        }
        for(int x=1; x<=c-1; x++){
            if(arr[x] == arr[x+1]) answer++;
            if(arr[x] == arr[x+1] - 2) answer++;
        }
    }

    cout << answer;
    
}