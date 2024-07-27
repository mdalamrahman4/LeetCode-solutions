class LRUCache {
    public:
    class node{
        public:
            int key,val;
            node*next,*prev;
            node(int key,int val){
                this->key=key;
                this->val=val;
            }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int capacity;
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node*newnode){
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node*delnode){
        node*tempnext=delnode->next;
        node*tempprev=delnode->prev;
        tempprev->next=tempnext;
        tempnext->prev=tempprev;
    }
    int get(int key_) {
        if(mp.find(key_)==mp.end()){
            return -1;
        }
        node*address=mp[key_];
        int res=address->val;
        mp.erase(key_);
        deletenode(address);
        addnode(address);
        mp[key_]=head->next;
        return res;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            node*existingnode=mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
        }
        if(mp.size()>=capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        mp[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */