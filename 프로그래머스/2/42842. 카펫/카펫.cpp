#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int x=3; x<2500; x++){
        for(int y=3; y<=x; y++){
            if(x * 2 + (y - 2) * 2 == brown){
                if((x-2) * (y-2) == yellow){
                    answer = {x, y};
                    return answer;
                }
            }
        }
    }
    return answer;
}