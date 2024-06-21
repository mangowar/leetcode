#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> buf;
        string op1;
        string op2;
        for(const auto& s: tokens)
        {
            if(s == "+")
            {
                int op1 = buf.top();
                buf.pop();
                int op2 = buf.top();
                buf.pop();
                buf.push(op1+op2);
            }
            else if(s == "-")
            {
                int op2 = buf.top();
                buf.pop();
                int op1 = buf.top();
                buf.pop();
                buf.push(op1-op2);
            }
            else if(s == "*")
            {
                int op1 = buf.top();
                buf.pop();
                int op2 = buf.top();
                buf.pop();
                buf.push(op1*op2);
            }
            else if(s == "/")
            {
                int op2 = buf.top();
                buf.pop();
                int op1 = buf.top();
                buf.pop();
                buf.push(op1/op2);
            }            
            else
                buf.push(stoi(s));
        }
        return buf.top();
    }
};