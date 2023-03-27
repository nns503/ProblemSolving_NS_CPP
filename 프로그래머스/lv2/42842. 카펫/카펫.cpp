#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; 
   set<int> s;
    int a = (brown + 4) / 2 ; 
    int b = brown + yellow;
    for(int i=2; i<=b/2; i++){
        if(b%i == 0){
            for(int j=i; j<=b/2; j*=2){
                s.insert(j);
            }
        }
    }
    for(int z : s){
        if(brown + 4 != ((z + (b/z)) * 2)) continue;
        else{
            answer.push_back(b/z);
            answer.push_back(z);
            break;
        }
    }
    return answer;
}

/*

*/