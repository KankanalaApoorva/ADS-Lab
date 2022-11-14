#include <bits/stdc++.h>
#include<inttypes.h>
using namespace std;

class node
{
 public:
 int data;
 node *npx;
};

node *XOR (node *a,node *b)
{
  return (node*)((uintptr_t) (a) ^  (uintptr_t) (b));
}

void insert(node **head,int key)
{
 node *new_node=new node();
 new_node->data=key;
 new_node->npx=*head;
 if(*head!=NULL)
 {
 (*head)->npx=XOR(new_node,(*head)->npx);
 }
*head=new_node;
}
node* deleteb(node** head)
{

    if (*head == NULL)
        cout<<"List Is Empty";
    else {
        node* temp = *head;

        *head = XOR(NULL, temp->npx);

        if (*head != NULL) {

            (*head)->npx
                = XOR(NULL, XOR(temp,
                                (*head)->npx));
        }

        free(temp);
    }
    return *head;
}
void print(node *head)
{
 node *curr=head;
 node *prev=NULL;
 node *next;
 cout<<"The Linked List as follows: "<<endl;
 while(curr!=NULL)
 {
  cout<<curr->data<<" ";
 next=XOR(prev,curr->npx);
 prev=curr;
 curr=next;
 }
}

void insertend(node **head,int data)
{
  node *new_node=new node();
  new_node->data=data;
  if(*head==NULL)
  {
   new_node->npx=*head;
   *head=new_node;
   }
  else
  {
 node *curr=*head;
 node *prev=NULL;
 node *next;
 while(XOR(prev,curr->npx)!=NULL)
 {
  next=XOR(prev,curr->npx);
  prev=curr;
  curr=next;
 }
 new_node->npx=curr;
 curr->npx=XOR(prev,new_node);
 }
}

node *deleteend(node *head)
{
  node *curr=head;
  node *prev=NULL;
  node *next=XOR(curr->npx,prev);
  if(head == NULL)
   return NULL;

   while(next!=NULL)
   {
    prev=curr;
    curr=next;
    next=XOR(curr->npx,prev);
   }
   if(prev!=NULL)
   prev->npx=XOR(prev->npx,curr);

    free(curr);
    return head;
}


int main()
{

 node *head=NULL;
int opt,key;
do
{
    cout<<"\nEnter the option"<<endl;
    cout<<"1.Insert Beginning"<<endl;
    cout<<"2.Insert at End"<<endl;
    cout<<"3.Delete Beginning"<<endl;
    cout<<"4.Delete at end"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Exit"<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:cout<<"Enter the element"<<endl;
        cin>>key;
        insert(&head,key);
        break;
        case 2:cout<<"Enter the element"<<endl;
        cin>>key;
        insertend(&head,key);
        break;
        case 3:deleteb(&head);
        break;
        case 4:deleteend(head);
        break;
        case 5:print(head);
        break;
        case 6:exit(0);

    }
}while(opt!=6);
return 0;
}
