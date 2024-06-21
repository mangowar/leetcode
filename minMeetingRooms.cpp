#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> times;
        times.push_back(intervals[0][1]);
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            int idx = 0;
            while(idx < times.size() && times[idx] > intervals[i][0]){
                idx++;
            }
            if(idx == times.size()){
                times.push_back(intervals[i][1]);
            }
            else{
                times[idx] = intervals[i][1];
            }
        }
        return times.size();
    }
};
int main()
{
    Solution s;
    vector<vector<int>> a = {{0, 30},{5, 10},{15, 20}};
    a = {{7, 10}, {2, 4}};
    int ans = s.minMeetingRooms(a);
    return 0;
}