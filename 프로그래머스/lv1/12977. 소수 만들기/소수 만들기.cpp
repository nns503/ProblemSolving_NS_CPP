#include <bits/stdc++.h>

using namespace std;

bool chk[10000];
vector<int> arr;
int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    for(int i=2; i<=3000; i++){
        if(chk[i]) continue;
        else{
            for(int j=i; j*i<=3000; j++){
                chk[i*j] = true;
            }
        }
    }
    
    for(int i=0; i<3; i++) arr.push_back(0);
    for(int i=3; i<nums.size(); i++) arr.push_back(1);
    
    do{
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0) temp += nums[i];
        }
        if(!chk[temp]) answer++;
    }while(next_permutation(arr.begin(), arr.end()));
    
    return answer;
}