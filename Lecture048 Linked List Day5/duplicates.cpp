/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}
pair<Node *, Node *> splitList(Node *head) {
        Node* head1_ref1 = head;
        Node* fast = head;
        Node* slow = head;
        // finding the middle and last node
        while(fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast -> next ->next;
        }
        Node* head1_ref2 = slow->next;
        if(fast->next == head){
            fast->next = head1_ref2;
        }
        else{
            fast->next->next = head1_ref2;
        }
        slow->next = head1_ref1;
        
        pair<Node*, Node*> ans;
        ans.first = head1_ref1;
        ans.second = head1_ref2;
    
        return ans;
    }
