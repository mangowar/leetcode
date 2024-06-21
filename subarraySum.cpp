#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int border = nums.size();
        int res = 0;
        unordered_map<int, int> pref_sums;
        int pref = 0;
        pref_sums[pref] = 1;
        for(int i = 0; i < border; i++)
        {
            pref += nums[i];
            int needed = pref - k;
            if(pref_sums.find(needed) != pref_sums.end()){
                res += pref_sums[needed];
            }
            pref_sums[pref]++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << s.subarraySum(nums, 2) << endl;
    return 0;
}