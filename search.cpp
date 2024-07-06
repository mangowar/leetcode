#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (nums.size()-1), mid;
        while (l <= r)
        {
            mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[l]) {
                if(target > nums[mid] || target < nums[l])
                    l = mid+1;
                else
                    r = mid-1;
            }
            else {
                if(target < nums[mid] || target > nums[r])
                    r = mid-1;
                else 
                    l = mid+1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    s.search(nums, 0);
    return 0;
}

/* 
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4 
*/
