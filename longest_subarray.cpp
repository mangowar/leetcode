#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int sub1 = 0;
        int sub2 = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i])
            {
                sub2++;
            }
            else {
                res = max(res, sub1+sub2);
                sub1 = sub2;
                sub2 = 0;
            }
        }
        res = max(res, sub1+sub2);
        if(res == nums.size())
            res--;
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 1, 1};
    cout << s.longestSubarray(v) << endl;
    return 0;
}