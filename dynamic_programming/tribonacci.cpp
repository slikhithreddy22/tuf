#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n){
    if (n == 0){
        return 0;
    }else if(n == 1 || n == 2){
        return 1;
    }
   int first = 0;
   int second = 1,third = 1;
   int ans;
    for(int i = 3;i<n+1;i++){
        ans = first+second+third;
        first = second;
        second = third;
        third = ans;
    }
    return ans;
}
int main(){
    cout << tribonacci(26);
    return 0;
}
