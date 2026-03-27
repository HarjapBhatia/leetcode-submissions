class MyCircularQueue {
private:
    int* arr;
    int front;
    int n;
    int mx;

public:
    MyCircularQueue(int k) {
        mx = k;
        arr = new int[mx];
        front=0;
        n=0;      
    }
    
    bool enQueue(int value) {
        if(n == mx) return false;
        int rear = (front+n)%mx;
        arr[rear]=value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if(n == 0) return false;
        front = (front+1)%mx;
        n--;
        return true;
    }
    
    int Front() {
        return n==0 ? -1 : arr[front];
    }
    
    int Rear() {
        int r = (front+n-1)%mx;
        return n==0 ? -1 : arr[r];
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==mx;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
