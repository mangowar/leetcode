#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        storage = nestedList;
        curr_end.push(storage.end());
        curr = storage.begin();
    }
    
    int next() {
        int res;
        while(curr != curr_end.top() && !curr->isInteger()){
            if(!curr->getList().empty()){
                iterator_stack.push(curr);
                curr_end.push(curr->getList().end());
                curr = curr->getList().begin();
            }
            else
                curr++;
        }
        res = curr->getInteger();
        curr++;
        while(curr == curr_end.top() && !iterator_stack.empty()){
            curr = iterator_stack.top();
            curr_end.pop();
            iterator_stack.pop();
            curr++;
        }
        return res;
    }
    
    bool hasNext() {
        while(curr != !curr->isInteger())
        return curr != storage.end();
    }
private:
    vector<NestedInteger> storage;
    stack<vector<NestedInteger>::const_iterator> curr_end;
    vector<NestedInteger>::const_iterator curr;
    stack<vector<NestedInteger>::const_iterator> iterator_stack;
};


int main(){
    return 0;
}
