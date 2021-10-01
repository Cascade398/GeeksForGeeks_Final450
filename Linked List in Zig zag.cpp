#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 
 Node *zigZack(Node* head);


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *ans = zigZack(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

Node *zigZack(Node* head)
{
    int flag=0;
    Node *root = head;
    while(head->next!=NULL)
    {
        if(flag==0)
        {
           if(head->next && head->next->data < head->data) 
                swap(head->data,head->next->data);
           flag=1; 
        }
        else
        {
            if(head->next && head->next->data > head->data) 
                swap(head->data,head->next->data);
            flag=0;
        }
        
        head = head->next;
    }
    return root;
}

