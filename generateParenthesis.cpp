#include<iostream>
#include<stack>
#include<vector>
#include <tuple>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<tuple<string, int, int>> buf;
        vector<string> res;
        buf.push(make_tuple("(", 1, 0));
        while(!buf.empty())
        {
            string p = get<0>(buf.top());
            int l_p = get<1>(buf.top());
            int r_p = get<2>(buf.top());
            buf.pop();
            if(l_p > r_p)
            {
                if((r_p + 1) == n)
                {
                    res.push_back(p+")");
                }
                buf.push(make_tuple(p+")", l_p, r_p+1));
            }
            if(l_p < n)
            {
                buf.push(make_tuple(p+"(", l_p+1, r_p));
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> a = s.generateParenthesis(12);
    sort(a.begin(), a.end());
    // for(const auto i: a)
    // {
    //     cout << i << endl;
    // }
    return 0;
}
