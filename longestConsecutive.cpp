#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> keys;
        int s = nums.size();
        for(int i = 0; i < s; i++)
        {
            keys[nums[i]] = true;
        }
        for(int i = 0; i < s; i++)
        {
            if(keys.count(nums[i] - 1))
            {
                keys[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(const auto p: keys)
        {
            if(p.second == true)
            {
                int j = 0;
                while(keys.count(p.first + j))
                {
                    j++;
                }
                maxlen = max(maxlen, j);
            }
        }
        return maxlen;
    }
};
int main()
{
    Solution s;
    vector<int> a = {0, 0, -1};
    s.longestConsecutive(a);
    return 0;
}