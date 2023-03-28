#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a>b) swap(a,b);
    while(true){
        if(a+1 == b && a%2 && !(b%2)) break;
        else{
            answer++;
            a = (a+1)/2;
            b = (b+1)/2;
        }
    }

    return answer;
}