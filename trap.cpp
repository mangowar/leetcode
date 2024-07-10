#include<iostream>
#include<vector>
using namespace std;
class Solution1 {
public:
    int trap(vector<int>& height) {
        int res{0}, l{1}, r = height.size()-2;
        int left_border = l-1;
        int right_border = r+1;
        while(l < right_border && r > left_border)
        {
            int buf = 0;
            while (l < right_border && height[l-1] <= height[l])
            {
                l++;
            }  
            left_border = l-1;    

            while (left_border < r && height[r] >= height[r+1])
            {
                r--;
            }
            right_border = r+1;

            if(height[left_border] < height[right_border])
            {
                while(l < right_border && height[left_border] > height[l])
                {
                    
                    buf += height[l];
                    l++;
                }  
                res += (l - left_border - 1) * min(height[l], height[left_border]) - buf;
                l++;
            }
            else
            {
                while(r > left_border && height[right_border] > height[r])
                {
                    buf += height[r];
                    r--;
                }
                res += (right_border - r - 1) * min(height[r], height[right_border]) - buf;
                r--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, res = 0;
        int left_max = height[l], right_max = height[r];
        while(l < r) {
            if(left_max > right_max) {
                l++;
                left_max = max(left_max, height[l]);
                res += left_max - height[l];
            }
            else {
                r--;
                right_max = max(right_max, height[r]);
                res += right_max - height[r];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(a);
    return 0;
}
