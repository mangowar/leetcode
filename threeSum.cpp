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
                }
                else if(nums[l] + nums[r] > -nums[i])
                {
                    r--;
                }
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    r--;
                    l++;
                }                            
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int>nums = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto res = s.threeSum(nums);

    return 0;
}