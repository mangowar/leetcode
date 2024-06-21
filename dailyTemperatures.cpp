#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> buf;
        vector<int> res(temperatures.size());
        buf.push(0);
        for(int i = 1; i < temperatures.size(); i++)
        {
            if(temperatures[buf.top()] >= temperatures[i])
            {
                buf.push(i);
            }
            else
            {
                while(!buf.empty() && temperatures[buf.top()] < temperatures[i])
                {
                    res[buf.top()] = i - buf.top();
                    buf.pop();
                }
                buf.push(i);
            }
        }
        while(!buf.empty())
        {
            res[buf.top()] = 0;
            buf.pop();
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> t = {73,74,75,71,69,72,76,73};
    auto a = s.dailyTemperatures(t);
    return 0;
}
