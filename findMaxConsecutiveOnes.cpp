#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int left{0}, right{0}, res = 0;
        int zeros = 0;
        for(right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                while(zeros >= 1)
                {
                    if(nums[left] == 0)
                    {
                        zeros--;
                    }
                    left++;
                }
                zeros++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}