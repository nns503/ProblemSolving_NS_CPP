#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer;
    int x = sizes[0][0];
    int y = sizes[0][1];
    answer = x*y;
    for(int i=1; i<sizes.size(); i++){
        int curx = sizes[i][0];
        int cury = sizes[i][1];
        
        int tx1 = max(curx, x);
        int ty1 = max(cury, y);
        int temp1 = tx1*ty1;
        
        int tx2 = max(cury, x);
        int ty2 = max(curx, y);
        int temp2 = tx2*ty2;
        if(temp1 < temp2){
            curx = tx1;
            cury = ty1;
        }
        else{
            curx = tx2;
            cury = ty2;
        }
        int temp = min(temp1, temp2);
        if(answer < temp){
            x = curx;
            y = cury;
        }
        answer = max(answer, temp);
        
    }
    return answer;
}