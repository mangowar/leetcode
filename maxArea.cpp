#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l{0}, r = height.size() - 1;
        int min_h = (height[l] < height[r]) ? l : r;
        int max_v = height[min_h] * r;
        while(l < r)
        {
            if(min_h == l)
            {
                do
                {
                    l++;
                }
                while(l < r && height[l] <= height[min_h]);
            }
            else{
                do
                {
                    r--;
                }
                while(l < r && height[r] <= height[min_h]);
            }
            min_h = (height[l] < height[r]) ? l : r;
            max_v = max(max_v, height[min_h] * (r - l));
        }
        return max_v;
    }
};
