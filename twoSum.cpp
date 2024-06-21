#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l{0}, r = nums.size() - 1;
        while(l < r)
        {
            if(nums[l] + nums[r] > target)
            {
                r--;
            }
            else if(nums[l] + nums[r] < target)
            {
                l++;
            }
            else{
                return {l+1, r+1};
            }
        }
        return {};
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> answer = s.twoSum(nums, target);
    cout << answer[0] << ' ' << answer[1] << endl;
    return 0;
}