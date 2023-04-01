#include <bits/stdc++.h>

using namespace std;

string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
int num[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};
int n = 0;

string solution(int a, int b) {
    for(int i=1; i<=a; i++){
        if(i==a) n += b;
        else n += num[i];
    }
    return day[(n-1) % 7];
}