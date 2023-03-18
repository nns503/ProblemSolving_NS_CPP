#include <bits/stdc++.h>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(double a : arr){
        answer += (a/arr.size());
    }
    return answer;
}