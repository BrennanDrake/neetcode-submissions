class BrowserHistory {
private:
    struct Node {
        string val;
        Node* prev;
        Node* next;
        Node(string val) : val(val), prev(nullptr), next(nullptr) {}
    };
    Node* cur;

public:
    BrowserHistory(string homepage) {
        cur = new Node(homepage);
    }
    
    void visit(string url) {
        cur->next = new Node(url);
        cur->next->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps){
        while(cur->prev != nullptr && steps > 0){
            cur = cur->prev;
            steps--;
        } 
        return cur->val;
    }
    
    string forward(int steps) {
        while(cur->next != nullptr && steps > 0){
            cur = cur->next;
            steps--;
        } 
        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */