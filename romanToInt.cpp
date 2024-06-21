#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> nums = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        char curr_char = s[0];
        int buf = nums[s[0]];
        for(int i = 1; i < s.size(); ++i) {
            if(nums[curr_char] == nums[s[i]]) {
                buf += nums[s[i]];
            }
            else if(nums[curr_char] < nums[s[i]]) {
                res += (nums[s[i]] - buf);
                buf = 0;
                curr_char = s[i];
            }
            else
            {
                res += buf;
                buf = nums[s[i]];
                curr_char = s[i];
            }
        }
        return res + buf;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("III") << endl;
    return 0;
}

/* Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 */
