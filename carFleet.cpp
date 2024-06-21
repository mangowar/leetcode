#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for(int i = 0; i < n; i++)
        {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        stack<pair<int, int>> buf;
        buf.push(cars[0]);
        for(int i = 1; i < n; i++)
        {
            double top_time = (double)(target - buf.top().first) / (double)buf.top().second;
            double cur_time = (double)(target - cars[i].first) / (double)cars[i].second;
            if(cur_time > top_time)
            {
                buf.push(cars[i]);
            }
        }
        return buf.size();
    }
};

int main()
{
    vector<int> position = {10,8,0,5,3}; 
    vector<int> speed = {2,4,1,1,3};
    Solution2 s;
    int a = s.carFleet(12, position, speed);
    return 0;
}