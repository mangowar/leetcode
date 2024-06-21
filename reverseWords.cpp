#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int r = 0;
        int l = 0;
        for(;r < s.size(); r++) {
            if(s[r] == ' ')
            {
                string sub = s.substr(l, r-l);
                string buf(sub.rbegin(), sub.rend());
                res += buf;
                res += s[r];
                l = r+1;
            }
        }
        string sub = s.substr(l, r-l);
        string buf(sub.rbegin(), sub.rend());
        res += buf;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest");
    return 0;
}