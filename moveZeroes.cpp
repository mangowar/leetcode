#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int border = nums.size();
//         for(int i = border-1; i >= 0; i--)
//         {
//             if(nums[i] == 0)
//             {
//                 int j = i;
//                 while(j+1 != border)
//                 {
//                     nums[j] = nums[j+1];
//                     nums[j+1] = 0;
//                     j++;
//                 }
//                 border--;
//             }
//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(i<n)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 0, 0,  2, 4, 3, 12};
    s.moveZeroes(nums);
    for(int i: nums)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
// 1 0 0 3 12
// 1 0 0 3 12
    //    |
    //  |