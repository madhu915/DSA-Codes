class MyCircularQueue {
public:
    int que[1000];
    int s,f,r;
    MyCircularQueue(int k) {    
        s=k;
        f=0;
        r=0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        que[r++]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        for(int i=0;i<r;i++)
            que[i]=que[i+1];
        r--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return que[0]; 
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return que[r-1];
    }
    
    bool isEmpty() {
        if(r==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(r==s)
            return true;
        return false;
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