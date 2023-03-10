#include <string>
#include <vector>

using namespace std;

int solve(int n){
    int cnt = 0;
    if(n == 1) return 1;
    for(int i = 1; i<=n/2; i++){
        if(n%i == 0){
            if(n/i == i) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        int cur = solve(i);
        if(cur % 2 == 0){
            answer += i;
        }
        else{
            answer -= i;
        }
    }
    return answer;
}