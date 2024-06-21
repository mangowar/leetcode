#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, __INT32_MAX__);
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++) {
            for(int value: coins) {
                if(i >= value){
                    dp[i] = min(dp[i], 1+dp[i-value]);
                }
            }
        }
        if(dp.back() == __INT32_MAX__)
            return -1;
        else
            return  dp.back();
    }
};