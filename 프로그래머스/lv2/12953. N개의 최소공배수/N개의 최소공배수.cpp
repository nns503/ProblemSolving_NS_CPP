#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    answer = arr[0];
    for(int i=1; i<arr.size(); i++){
        int cur = arr[i];
        int a = 1;
        while(answer*a%cur!=0){
            a++;
        }
        answer = answer*a;
    }
    return answer;
}