#include <cctype>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a;
        int b;

        for(string t : tokens){
            
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if(t == "+"){
                    stk.push(b + a);
                    continue;
                }else if(t == "-"){
                    stk.push(b - a);
                    continue;
                }else if (t == "*"){
                    stk.push(b * a);
                    continue;
                }else if (t == "/"){
                    stk.push(b / a);
                    continue;
                }
            }
            
            // confirmed not an operand
            stk.push(stoi(t));
            continue;   
        }
        return stk.top();
    }
};
