#include<vector>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int s{0};
        for(int f = 0; f < firstList.size(); f++){
            if(s < secondList.size() && secondList[s][0] <= firstList[f][1] && secondList[s][1] >= firstList[f][0]){
                res.push_back({max(firstList[f][0], secondList[s][0]), min(firstList[f][1], secondList[s][1])});
            }
            if(s < secondList.size() && secondList[s][1] < firstList[f][1]){
                s++;
                f--;
            }
        } 
        return res;
    }
};
int main()
{
    vector<vector<int>> f = {{1,3},{5,9}};
    vector<vector<int>> s = {};
    Solution sol;
    sol.intervalIntersection(f,s);
}

//    _________
//  ____ 
//     ____ 
//            ____ 