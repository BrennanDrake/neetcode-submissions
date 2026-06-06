class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            switch(c){
                case '[':
                    stack.push(c);
                    break;
                case '{':
                    stack.push(c);
                    break;
                case '(':
                    stack.push(c);
                    break;
                case ')':
                    if(!stack.empty() && stack.top() == '('){
                       stack.pop();
                    } else return false;
                    break;
                case '}':
                    if(!stack.empty() && stack.top() == '{'){
                       stack.pop();
                    } else return false;
                    break;
                case ']':
                    if(!stack.empty() && stack.top() == '['){
                       stack.pop();
                    } else return false;
                    break;

            }
        }
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};
