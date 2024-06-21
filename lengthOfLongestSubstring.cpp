#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l{0}, r{0};
        int res = 0;
        int size = s.size();
        unordered_set<char> substring;
        for(; r<size; r++)
        {
            if(substring.find(s[r]) != substring.end())
            {
                res = max(res, r-l);
                do
                {
                    substring.erase(s[l]);
                    l++;
                } 
                while(s[l-1] != s[r]);
            }
            substring.insert(s[r]);
        }
        res = max(res, r-l);
        return res;
    }
};

int main() {
    string str;
    Solution s;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str);
    return 0;
}