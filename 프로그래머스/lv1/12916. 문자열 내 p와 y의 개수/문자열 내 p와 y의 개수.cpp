#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    for(char a : s){
        a = tolower(a);
        if(a == 'p') p++;
        else if(a == 'y') y++;
    }
    

    return p==y;
}