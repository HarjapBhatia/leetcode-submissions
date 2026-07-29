class Node{
public:
    int val;
    Node* prev, *next;
    Node(int x){
        val=x; prev=nullptr; next=nullptr;
    }
};

class MyCircularDeque {
    Node* head=nullptr, *tail=nullptr;
    int cnt=0, cap=0;
public:
    MyCircularDeque(int k) {
        head = tail = nullptr; cap=k; cnt=0;
    }
    
    bool insertFront(int value) {
        if (cnt == cap) return false;
        Node *temp = new Node(value);
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if (cnt == cap) return false;
        Node *temp = new Node(value);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(cnt==0 || !head) return false;
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(cnt==0 || !tail) return false;
        Node* temp = tail;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        cnt--;
        return true;
    }
    
    int getFront() {
        if(!head) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!tail) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
