class MyCircularDeque {
public:
    vector<int>q;
    int front,rear;
    MyCircularDeque(int k) {
        q.resize(k,0);
        front=-1;
        rear=-1;
    }
    
    bool insertFront(int value) {
        if(isFull())    return false;
        else{
            if(front==-1){
                insertLast(value);
            }
            else{
                front=(front+(q.size()-1))%q.size();
                q[front]=value;
            }
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())    return false;
        else{
            if(front==-1)   front=0;
            rear=(rear+1)%q.size();
            q[rear]=value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())   return false;
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }else{
                front=(front+1)%q.size();
            }
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())   return false;
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }else{
                rear=(rear+q.size()-1)%q.size();
            }
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())   return -1;
        return q[front];
    }
    
    int getRear() {
        if(isEmpty())   return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1)   return true;
        return false;
    }
    
    bool isFull() {
        if((rear+1)%q.size()==front){
            return true;
        }
        return false;
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