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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) 
            return nullptr;
        if(list1 && !list2)
        {
            list1->next = mergeTwoLists(list1->next, nullptr);
            return list1;
        }
        else if(!list1 && list2) {
            list2->next = mergeTwoLists(nullptr, list2->next);
            return list2;
        }
        else {
            if(list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
    }
        
};

int main() {
    ListNode* root = nullptr;
    ListNode* p1 = new(ListNode);

}