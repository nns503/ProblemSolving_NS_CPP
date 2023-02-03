#include <string>
#include <vector>
#include <algorithm>
    
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int ranking[7] = {6,6,5,4,3,2,1};
    int correct = 0;
    int zero = 0;
    
    for(int i=0;i<lottos.size();i++){
        for(int j=0;j<win_nums.size();j++){
            if(lottos[i]==0){
                zero++;
                break;
            }
            else if(lottos[i]==win_nums[j]){
                correct++;
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(ranking[correct+zero]);
    answer.push_back(ranking[correct]);
    return answer;
}