#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i=0;i<moves.size();i++){
        int row = moves[i]-1;
        
        for(int j=0;j<board.size();j++){
            
            int target = board[j][row];
            if(target!=0){
                board[j][row]=0;
                if(!s.empty()&&s.top()==target){
                    s.pop();
                    answer+=2;
                }
                else{
                    s.push(target);
                }
                break;
            }
            
        }
    }
    
    
    return answer;
}

