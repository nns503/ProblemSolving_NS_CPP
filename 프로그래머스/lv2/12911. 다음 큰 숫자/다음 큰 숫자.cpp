#include <bits/stdc++.h>

using namespace std;

int func(int n){
    int a = 0;
    while(n>0){
        if (n%2 == 1) a++;
        n /= 2;
    }    
    return a;
}

int solution(int n) {
    int first = func(n);
    n++;
    while(first != func(n)){
        n++;
    }
    return n;
}