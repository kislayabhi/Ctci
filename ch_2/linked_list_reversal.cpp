#include <iostream>
#include "ideal_list.h"

using namespace std;

struct node* fix(struct node* first, struct node* rest)
// Walk the rest till NULL. remove NULL and join first
{
	struct node* running_ptr=rest;
	while(running_ptr->next!=NULL)
	{
		running_ptr=running_ptr->next;
	}
	running_ptr->next=first;
	first->next=NULL;
	return rest;
}


// Reverses the linked list and gives its head. 
struct node* reverse_ll(struct node* curr_ptr)
{
	struct node* rest;
	if(curr_ptr->next==NULL)
	{
		rest=curr_ptr;
		rest->next=NULL;
		return fix(curr_ptr, rest);
	}
	else
	{
		// Separate the first from the rest	
		rest=curr_ptr->next;
		return fix(curr_ptr, reverse_ll(rest));
	}

	// Fix the two linked lists together.
	
}

int main()
{
	struct node* node1 = new(struct node);
	node1->data=1;
	node1->next=NULL;

	struct node* head=node1;
	
	// Populate a linked list
	int i;
	for(i=1; i<9; ++i)
		add_node(&head, i, 1+i);

	// Traverse the list.
	struct node* curr_ptr;
	curr_ptr=head;
	while(curr_ptr!=NULL)
	{
		cout<<curr_ptr->data<<endl;
		curr_ptr=curr_ptr->next;
	}

	cout<<"\n"<<endl;
	head = reverse_ll(head);

	curr_ptr=head;
	while(curr_ptr!=NULL)
	{
		cout<<curr_ptr->data<<endl;
		curr_ptr=curr_ptr->next;
	}

	

}