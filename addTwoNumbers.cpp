#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result_node;
        if(l1 == nullptr && l2 == nullptr)
            result_node = nullptr;
        else if(l1 || l2) {
            result_node = new(ListNode);
            int res;
            if(l1 && l2) {
                res = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else {
                if(l1) {
                    res = l1->val;
                    l1 = l1->next;
                }
                if(l2) {
                    res = l2->val;
                    l2 = l2->next;
                }
            }
            if(res/10) {
                    if(!l1)
                    {
                        l1 = new(ListNode);
                        l1->next = nullptr;
                        l1->val = 0;
                    }
                    l1->val++;
                }
            result_node->val = res%10;
            result_node->next = addTwoNumbers(l1, l2);
        }
        return result_node;
    }
};

ListNode* to_list(vector<int> v) {
    ListNode* root = nullptr;
    for(int i = v.size()-1; i >= 0; i--) {
        ListNode* ptr = new(ListNode);
        ptr->val = v[i];
        ptr->next = root;
        root = ptr;
    }
    cout << endl;
    return root;
}

void DelList(ListNode* l) {
    while(l) {
        ListNode* ptr = l;
        l = l->next;
        delete(ptr);
    }
}

int main() {
    ListNode* l1 = to_list({9,9,9,9,9,9,9});
    ListNode* l2 = to_list({9,9,9,9});
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    DelList(l1);
    DelList(l2);
    DelList(res);
    return 0;
}