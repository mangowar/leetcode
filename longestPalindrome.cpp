#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 1; i < s.size()-1; i++) {
            int l = i-1, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if(r-l-1 > res.size()) 
                res = s.substr(l+1, r-l-1);
            l = i-1, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if(r-l-1 > res.size()) 
                res = s.substr(l+1, r-l-1);
        }
        return res;
    }
};