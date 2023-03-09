#include <bits/stdc++.h>

using namespace std;

int a1[17][17];
int a2[17][17];
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> as;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a1[i][j] = arr1[i] % 2;
            a2[i][j] = arr2[i] % 2;
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
    }
    
    for(int i=0; i<n; i++){
        string temp;
        for(int j=n-1; j>=0; j--){
            if(a1[i][j] == 1 || a2[i][j] == 1){
                temp += "#";
            }
            else{
                temp += " ";
            }
        }
        as.push_back(temp);
    }
    return as;
}