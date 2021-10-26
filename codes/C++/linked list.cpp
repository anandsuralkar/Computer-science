#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
};
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}    
void insertAfter(struct Node* current_node,int pos, int new_data) //struct node* current_node should be given start node while calling the function.
{
    for(int i=0;i<pos;i++){
    	if (current_node == NULL)
	    {
	      cout<<"the given previous node cannot be NULL";
	      return;
	    }
	    current_node=current_node->next;
	}
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = current_node->next;
    current_node->next = new_node;
}
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void printList(struct Node *node)
{
  while (node != NULL)
  {
     cout<<node->data<<" ";
     node = node->next;
  }
  cout<<endl;
}
void choice(struct Node* head){
	int ch=1;
	while(ch!=0){
	int val;
	cout<<"0.Exit \n1.Add new node at first \n2.Add new node at last \n3.Add new node after given position \n4.Display list \nEnter a choice ";
	cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter value to enter at start ";
				cin>>val;
				push(&head, val);
				break;
			case 2:
				cout<<"enter value to enter at last ";
				cin>>val;
				append(&head, val);

				break;
			case 3:
				int pos;
				cout<<"enter position to add new node ";
				cin>>pos;pos--;
				cout<<"enter value to inster at ";
				cin>>val;
				insertAfter(head,pos,val);
				break;
			case 4:
				cout<<"\n Created Linked list is: ";
				printList(head);
				break;
		}
	}
}
int main()
{
  struct Node* head = NULL;
  choice(head);
  return 0;
}
