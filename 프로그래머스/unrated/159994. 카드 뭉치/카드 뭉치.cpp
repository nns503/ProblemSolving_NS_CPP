#include <bits/stdc++.h>

using namespace std;

int p1, p2;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    for(int i=0; i<goal.size(); i++){
        if(p1 != cards1.size() && goal[i] == cards1[p1]){
            p1++;
        }
        else if(p2 != cards2.size() && goal[i] == cards2[p2]){
            p2++;
        }
        else {  
            return "No";
        }
    }
    return "Yes";
}