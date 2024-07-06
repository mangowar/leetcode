#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, min_num = nums[0];
        while(l <= r) {
            int mid = (l+r)/2;
            min_num = min(min_num, nums[mid]);
            if(nums[mid] >= nums[l] && nums[mid] >= nums[r])
            {
                l = mid+1;
            }
            else {
                min_num = min(min_num, nums[mid]);
                r = mid-1;
            }
        }
        return min_num;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution s;
    s.findMin(nums);
    return 0;
}

/* 
Input: nums = [3,4,5,1,2]
Output: 1
 */
