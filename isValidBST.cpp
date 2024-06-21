#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        long left = (long)INT32_MIN-1;
        long right = (long)INT32_MAX+1;
        return check2(left, right, root);
    }
    bool check2(long left, long right, TreeNode* root){
        if(root == nullptr)
            return true;
        if(root->val > left && root->val < right)
            return check2(left, root->val, root->left) && check2(root->val, right, root->right);
        else
            return false;
    }
};