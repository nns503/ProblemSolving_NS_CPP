#include <bits/stdc++.h>

using namespace std;

bool nums[1000010];
int solution(int n) {
    int answer = 0;
    for(long long i=2; i<=n; i++){
        if(nums[i]) continue;
        else{
            for(long long j=i*i; j<=n; j+=i)
                nums[j] = true;
        }
    }
    
    for(int i=2; i<=n; i++){
        if(!nums[i]) answer++;
    }
    
    return answer;
}