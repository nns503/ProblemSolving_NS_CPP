#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for(int a : nums) s.insert(a);
    
    return (s.size()<nums.size()/2)?s.size():(nums.size()/2);
}