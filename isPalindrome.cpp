#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string buf;
        for(const char c: s)
        {
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                buf.push_back(c);
            if(c >= 'A' && c <= 'Z')
                buf.push_back(c - 'A' + 'a');
        }
        int l{0}, r = buf.size() - 1;
        while(l < r)
        {
            if(buf[l] != buf[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
int main()
{
    return 0;
}