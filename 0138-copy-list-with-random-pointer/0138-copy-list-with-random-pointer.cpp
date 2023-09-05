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
        if(head==NULL)
            return NULL;
        
        Node *curr=head;
        Node *temp=head;
        while(curr)
        {
            Node *node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=curr->next->next;
        }
        curr=head;
       while(curr && curr->next!=NULL)
       {    
           
           if(curr->random==NULL)
           {
               curr->next->random=NULL;
           }
           else
           {
               curr->next->random=curr->random->next;
           }
           curr=curr->next->next;
       }
        
        curr=head;
        temp=head->next;
        Node *node=temp;
        while(curr && temp)
        {
            curr->next=curr->next==NULL ? NULL : curr->next->next;
            curr=curr->next;
            temp->next=temp->next==NULL ? NULL : temp->next->next;
            temp=temp->next;
        }
        return node;
        
        
        
            return curr;
    }
};