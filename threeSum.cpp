#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l, r;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i >  0 && nums[i] == nums[i-1])
                continue;
            l = i+1;
            r = nums.size() - 1;
            while(l < r){
                if(nums[l] + nums[r] < -nums[i])
                {
                    l++;
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                }
                else if(nums[l] + nums[r] > -nums[i])
                {
                    r--;
                    while(r < nums.size() -1 && l < r && nums[r] == nums[r+1])
                        r--;
                }
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                    while(r < nums.size() -1 && l < r && nums[r] == nums[r+1])
                        r--;
                }
                
                
            }
        }
        return res;
    }
    
};
int main()
{
    Solution s;
    vector<int>nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    auto res = s.threeSum(nums);

    return 0;
}