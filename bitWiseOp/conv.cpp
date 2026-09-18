#include <bits/stdc++.h>
using namespace std;

string conv2Binary(int n){
    if (n == 0 || n == 1){
        return to_string(n);
    }
    return (conv2Binary(n/2))+to_string(n%2);
}

int conv2Int(string s){
    int ans = 0;
    for(int i = 0;i<s.size();i++){
        ans += (s[i]-'0') * pow(2,s.size()-i-1);
    }
    return ans;
}

int oddOrEven(int n){
    return (n & 1) == 0;
}

int ibitSetOrNot(int n,int i){
    return (n >> i) & 1 ;
}

int toogleBit(int n, int i){
    cout << conv2Binary(n) << endl;
    n = n ^ (1<<i);
    cout << conv2Binary(n) << endl;
    return 0;
}

int minBitFlips(int start, int goal){
    int xoro = start ^ goal;
    int count = 0;
    while (xoro){
        if (xoro & 1){
            count++;
        }
        xoro = xoro >> 1;
    }
    return count;
}

vector<vector<int> subsets(vector<int> &nums){
    vector<vector<int>> subsets;
    for(int mask = 0;mask<(1<<nums.size());i++){
        vector<int> set;
        for(int i : nums){
            if (mask & 1){
                set.push_back(i);
            }
        }
        subsets.push_back(set);
    }
    return subsets;
}
int main(){
    // string ans = conv2Binary(13);
    // int inte = conv2Int(ans);
    // cout << ans << endl;
    // cout << inte << endl;
    // cout << oddOrEven(25) << endl;
    // cout << ibitSetOrNot(13,1) << endl;
    // toogleBit(13,0);
    cout << minBitFlips(10,7) << endl;
    cout << minBitFlips(3,4) << endl;
    return 0;
}
