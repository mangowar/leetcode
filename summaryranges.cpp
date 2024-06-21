#include <string>
#include <vector>
#include <iostream>

using namespace std;
// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& n) 
// {
// 	vector<string> r;
// 	for (auto p(0), q(0); q<size(n); ++q)
// 		if (q+1==size(n) || n[q+1]!=n[q]+1)
// 		{
// 			r.emplace_back( p!=q ? to_string(n[p])+"->"+to_string(n[q]) : to_string(n[p]) );
// 			p=q+1;
// 		}
// 	return r;
// }
// };
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int> range;
        vector<string> res;
        if(nums.empty())
            return res;
        range.push_back(nums[0]);
        int j{0};
        for(int i = 1; i < nums.size(); i++)
        {
            if((long long)(nums[i] - range[j]) <= 1)
            {
                range.push_back(nums[i]);
                j++;
            }
            else 
            {
                if(range.size() > 1)
                    res.push_back(to_string(*range.begin()) + "->" + to_string(*range.rbegin()));
                else
                    res.push_back(to_string(range[0]));
                range.clear();
                range.push_back(nums[i]);
                j = 0;
            }
        }
        if(range.size() > 1)
            res.push_back(to_string(*range.begin()) + "->" + to_string(*range.rbegin()));
        else
            res.push_back(to_string(range[0]));
        return res;;
    }
};
int main()
{
    Solution s;
    vector<int> v = {0,2,3,4,6,8,9};
    for (auto p: s.summaryRanges(v))
    {
        cout << p << endl;
    }
    return 0;
}