#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int merge_size = (nums1.size() + nums2.size() + 1)/2;
        int mid1 = (nums1.size()+1)/2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (true)
        {
            int mid2 = merge_size-mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < nums1.size()) {
                r1 = nums1[mid1];
            }
            if(mid1-1 >= 0)
            {
                l1 = nums1[mid1-1];
            }
            if(mid2 < nums2.size()) {
                r2 = nums2[mid2];
            }
            if(mid2 - 1 >= 0) {
                l2 = nums2[mid2 - 1];
            }
            if(l1 <= r2 && l2 <= r1) {
                if((n1+n2)%2) {
                    return max(l1 , l2);
                }
                else {
                    return ((double)(max(l1, l2) + min(r1, r2))/2.0);
                } 
            }
            else if(l1 > r2)
                mid1--;
            else 
                mid1++;
        }
        return 0;
    }
};

int main() {
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {30, 40, 50, 60, 70};
    Solution s;
    cout << s.findMedianSortedArrays(n1, n2) << endl;
    return 0;
}