using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(int i=1;i<=count;i++){
        answer+=price*i;
    }
    
    if(answer < 0) return 0;

    return (answer-money>0)?answer-money:0;
}