/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node *, Node*> m;
        Node *curr=head;
        
        while(curr!=NULL)
        {
            m[curr]=new Node(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        while(curr!=NULL)
        {
            m[curr]->next=m[curr->next];
            m[curr]->random=m[curr->random];
            curr=curr->next;
        }
        return m[head];
    }
};