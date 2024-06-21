#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
            return false;
        int pos = 0;
        int n = s.size();
        for(char c: t) {
            if(pos < n && c == s[pos])
                pos++;
            else if(pos == n)
                return true;
        }
        return pos == n;
    }
};