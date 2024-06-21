#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int i = 0;
        while(i < n) {
            res ^= nums[i];
            i++;
        }
        return res;
    }
};