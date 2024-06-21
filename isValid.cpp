#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string& s) {
        stack<int> buf;
        for(const auto& c: s)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                buf.push(c);
            }
            else if (c == ')' || c == ']' || c == '}')
            {
                if(buf.empty())
                {
                    return false;
                }
                else
                {
                    if((c == ')' && buf.top() == '(') || (c == ']' && buf.top() == '[') || (c == '}' && buf.top() == '{'))
                        buf.pop();
                    else
                        return false;
                }
            }
        }
        return buf.empty();
    }
};
