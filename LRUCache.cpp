#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node* prev;
    Node* next;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        if(capacity > 0)
            this->capacity = capacity;
        else
            this->capacity = 0;
    }
    
    int get(int key) {
        if(values.find(key) != values.end()){
            if(start != mins[key])
            {
                Node* buf = mins[key];
                buf->prev->next = buf->next;
                if(buf != end)
                {
                    buf->next->prev = buf->prev;
                }
                else{
                    end = end->prev;
                    end->next = nullptr;
                }
                buf->next = start;
                start->prev = buf;
                buf->prev = nullptr;
                start = buf;
            }
            return values[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(values.find(key) != values.end()){
            if(start != mins[key]){
                Node* buf = mins[key];
                buf->prev->next = buf->next;
                if(buf->next != nullptr)
                {
                    buf->next->prev = buf->prev;
                }
                else
                {
                    end = end->prev;
                }
                buf->next = start;
                buf->prev = nullptr;
                start->prev = buf;
                start = buf;
            }
            values[key] = value;
        }
        else{
            Node* buf = new Node;
            buf->key = key;
            buf->prev = nullptr;
            buf->next = start;
            values[key] = value;
            mins[key] = buf;
            if(start != nullptr)
            {
                start->prev = buf;
            }
            else{
                end = buf;
            }
            start = buf;
            if(capacity > 0)
                capacity--;
            else{
                int k = end->key;
                Node* del = end;
                end = end->prev;
                end->next = nullptr;
                delete(del);
                mins.erase(k);
                values.erase(k);
            }
        }
    }
private:
    int capacity;
    unordered_map<int, int> values;
    unordered_map<int, Node*> mins;
    Node* start = nullptr;
    Node* end = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache l(2);
    l.put(2, 1);
    l.put(1, 1);
    l.put(2, 3);
    l.put(4, 1);
    int a = l.get(1);
    a = l.get(2);
    return 0;
}