class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        int cur_min;
        if(stk.empty()){
            cur_min = val;
        }else{
            cur_min = min(val,stk.top().second);
            }
        stk.push({val,cur_min});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top(){
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};