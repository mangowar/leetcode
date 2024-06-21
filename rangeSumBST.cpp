#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) {
            return 0;
        }
        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        else if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        else {
            return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }
    }
};