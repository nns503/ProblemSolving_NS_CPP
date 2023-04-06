#include <bits/stdc++.h>

using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    vector<int> arr;
    for(int i=0; i<n; i++) arr.push_back(i);
    do{
        int h = k;
        for(int i=0; i<n; i++){
            if(h < dungeons[arr[i]][0]) break;
            h -= dungeons[arr[i]][1];
            answer = max(answer, i+1);
        }

    }while(next_permutation(arr.begin(), arr.end()));
    return answer;
}