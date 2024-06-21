#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};

int main() {
    Solution s;
    cout << s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    return 0;
}