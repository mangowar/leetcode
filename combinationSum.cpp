#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        for(int i: candidates) {
            for(int j = i; j <= target; j++) {
                for(auto v:dp[j-i])
                {
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }
        return dp[target];
    }
};

/*
[2,3,6,7]
*/