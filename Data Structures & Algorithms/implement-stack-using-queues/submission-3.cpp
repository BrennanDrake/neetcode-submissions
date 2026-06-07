class MyStack {
public:
    queue<int> qu1;

    MyStack() {
    }
    
    void push(int x) {
        qu1.push(x);
    }
    
    int pop() {
        int sz = qu1.size();
        //Cycle to get the queue front to the stack top
        for(int i = 0; i < sz-1; i++){
            qu1.push(qu1.front());
            qu1.pop();
        }
        //Record and remove stack top
        int frt = qu1.front();
        qu1.pop();
        return frt;
    }
    
    int top() {
        int sz = qu1.size();

        //Cycle to get the queue front to the stack top
        for(int i = 0; i < sz-1; i++){
            qu1.push(qu1.front());
            qu1.pop();
        }
        //Record and remove stack top
        int frt = qu1.front();
        qu1.pop();
        qu1.push(frt);
        return frt;
    }
    
    bool empty() {
        return qu1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */