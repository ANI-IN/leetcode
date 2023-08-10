class LRUCache {
    
    class node{
            public:
            int key;
            int val;

            node *next;
            node *prev;

            node(int k,int v)
            {
                key=k;
                val=v;
            }
        
    };
    
    node *head= new node(-1,-1);
    node *tail= new node(-1,-1);
    int sz;
    unordered_map<int,node*>m;
    
    
public:
    
    void addnode(node *curr)
    {
        node *temp=head->next;
        head->next=curr;
        temp->prev=curr;
        curr->next=temp;
        curr->prev=head;
                
    }
    
    void deletenode(node *curr)
    {
        node *delprev=curr->prev;
        node *delnext=curr->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        
        
    }
    LRUCache(int capacity) {
        
        head->next=tail;
        tail->prev=head;
        sz=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node *resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=resnode;
            return res;
            
            
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node *curr=m[key];
            m.erase(key);
            deletenode(curr);
        }
        
        if(sz==m.size())
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        node *curr=new node(key,value);
        addnode(curr);
        m[key]=curr;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */