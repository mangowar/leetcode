#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);
        for(int i = 1; i < n; i++)
        {
            /* Элемент на позиции i - это произведение всех элементов nums до элемента в позиции i */
            pref[i] = pref[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; --i) 
        {
            /* Элемент на позиции i - это произведение всех элементов nums после элемента в позиции i */
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < n; i++)
        {
            result[i] = pref[i] * suff[i];
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> a = {1, 2, 3, 4};
    auto b = s.productExceptSelf(a);
    return 0;
}