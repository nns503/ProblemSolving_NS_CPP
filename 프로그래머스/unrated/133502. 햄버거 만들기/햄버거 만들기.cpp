#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    for(int i=0; i<ingredient.size(); i++){
        v.push_back(ingredient[i]);
        int len = v.size();
        if(len >= 4){
            if(v[len-1] == 1 && v[len-2] == 3 && v[len-3] == 2 && v[len-4] == 1){
                v.erase(v.end()-4, v.end());
                answer++;
                
            }
            }
        }
    return answer;
}