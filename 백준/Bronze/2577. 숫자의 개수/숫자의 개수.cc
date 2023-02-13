#include <bits/stdc++.h>

using namespace std; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    int num[10]={0,};
    cin >> a >> b >> c;
    int m = a*b*c;
    while(m>0){
        num[m%10]++;
        m/=10;
    } 
    for(int i=0;i<10;i++)
        cout << num[i] << " ";
}