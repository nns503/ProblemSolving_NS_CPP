#include <bits/stdc++.h>

using namespace std;

int nums[100001];
int solution(int number, int limit, int power) {
    int answer = 0;
    nums[1] = 1;
    for(int i=2; i<=100000; i++){
        nums[i]++;
        for(int j=1; j*i<=100000; j++){
            nums[i*j]++; 
        }     
    }
    for(int i=1; i<=number; i++){
        if(nums[i] <= limit) answer += nums[i];
        else answer += power;
    }
    return answer;
}