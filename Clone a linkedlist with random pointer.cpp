class Solution
{
    public:
    void InsertAtTail(Node *&head,Node *&tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node *copyList(Node *head)
    {
        //creat a clone list 
        Node *cloneHead=NULL;
        Node *cloneTail=NULL;
        
        Node *temp=head;
        while(temp!=NULL){
            InsertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        //create a map
        unordered_map<Node*,Node*> mp;
        Node *orignal=head;
        Node *clone=cloneHead;
        while(orignal!=NULL && clone!=NULL){
            mp[orignal]=clone;
            orignal=orignal->next;
            clone=clone->next;
        }
        orignal=head;
        clone=cloneHead;
        while(orignal!=NULL&& clone!=NULL){
            clone->arb=mp[orignal->arb];
            orignal=orignal->next;
            clone=clone->next;
        }
        return cloneHead;
    }

};
