#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
Node* addOne(Node *head);
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
Node *ZZZZZZZZZZ(Node *head)
{
    Node * prev   = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void print(struct Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
// This function mainly uses addOneUtil().
int main() {
	// your code goes here
	int T;
	cin>>T;
	int no;
	while(T--)
	{
		struct Node *head = NULL;
        struct Node *temp = head;
        
		cin>>no;
		while(no!=0)
			{
			if(head==NULL)
			head=temp=newNode(no%10);
			else
			{
				temp->next = newNode(no%10);
				temp=temp->next;
			}
			no/=10;
		}
		head = ZZZZZZZZZZ(head);
		
		head=addOne(head);
		print(head);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* next;
}; */


// Returns new head of linked List.
Node *Reverse(Node *head)
{
    Node *prev=NULL,*curr=head,*next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *addOne(Node *head)
{
   // Your Code here
   head = Reverse(head);
   Node *curr=head;
   int flag=0;
   while(curr)
   {
       int x = curr->data;
       if(x+1<=9)
       {
           curr->data = x+1;
           flag=1;
           break;
       }
       curr->data = 0;
       
       curr=curr->next;
   }
   
   head = Reverse(head);
   if(flag==0) 
   {
       Node *temp = new Node();
       temp->data = 1;
       temp->next = head;
       head = temp;
   }
   return head;
   
   
   
   
   
   
}


