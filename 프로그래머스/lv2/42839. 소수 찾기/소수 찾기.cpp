#include <bits/stdc++.h>

using namespace std;

const int M = 9999999;
bool dc[10000000];
bool ans[10000000];
vector<int> arr;

int solution(string numbers) {
    int answer = 0;
    
    for(char c : numbers){
        arr.push_back(c-'0');
    }
    
    sort(arr.begin(), arr.end());
    
    dc[0] = true;
    dc[1] = true;
    for(int i=2; i<=M; i++){
        if(dc[i]) continue;
        for(int j=i+i; j<=M; j+=i){
            dc[j] = true;
        }
    }
    
    do{
        for(int i=1; i<=numbers.size(); i++){
            int n = 0;
            for(int k=0; k<i; k++){
                n *= 10;
                n += arr[k];
            }
            if(!dc[n] && !ans[n]){
                ans[n] = true;
                answer++;
            }
        }
    }while(next_permutation(arr.begin(), arr.end()));
    return answer;
}