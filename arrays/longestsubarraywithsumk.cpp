#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {10, 5, 2, 7, 1, -10};
    unordered_map<int,int> mp;
    mp[0] = -1;
    int ans = 0;
    int sum = 0;
    int k = 15;
    for(int i = 0;i<v.size();i++){
        sum += v[i];
        if (mp.count(sum-k)){
            ans = max(ans,i-mp[sum-k]);
        }else{
            mp[sum] = i;
        }
    }
    cout << ans;
    return 0;
}
