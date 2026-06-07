//class for each element
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    //constructor
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    
    MyLinkedList() {
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* curr = head;

        for(int i = 0; i<index; i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(head != nullptr){
            head->prev = newnode;
            newnode->next = head;
        }
        head = newnode;
        if(head->next == nullptr){
            tail = head;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
        if(tail != nullptr){
            tail->next = newnode;
            newnode->prev = tail;
        }
        tail = newnode;
        if(tail->prev == nullptr){
            head = tail;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }else if (index == 0) {
            addAtHead(val);
            return;
        } else if (index == size){
            addAtTail(val);
            return;
        }
        Node* curr = head;
        Node* newnode = new Node(val);
        
        for(int i = 0; i<index-1; i++){
            curr = curr->next;
        }

        Node* newnext = curr->next;
        Node* newprev = curr;
        curr->next = newnode;
        newnode->next = newnext;
        newnode->prev = newprev;
        newnext->prev = newnode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index > size-1){
            return;
        }else if(size==1){
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }else if(index == 0){
            Node* oldhead = head;
            head = head->next;
            head->prev = nullptr;
            delete oldhead;
            size--;
            return;
        } else if (index == size-1){
            Node* oldtail = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete oldtail;
            size--;
            return;
        }

        Node* curr = head;

        for(int i = 0; i<index; i++){
            curr = curr->next;
        }

        Node* prev = curr->prev;
        Node* next = curr->next;
        prev->next = next;
        next->prev = prev;

        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */