#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    for(long long i=1; i*i<=n; i++){
        if(i*i == n){
            return (i+1) * (i+1);
        } 
    }
    return -1;
}