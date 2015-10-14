// Here I am trying to implement the operations of a doubly linked list.

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

// Inputs
// reference to the head pointer.
// Index of the node to be added.
// Value of the data to be added.
void add_node(struct node** ptr2head, int index, int value)
{
	// Create a node by dynamically allocating it
	struct node* new_node=new(struct node);
	new_node->data=value;
	struct node* head=*ptr2head;

	// Adding nodes to the head has to be done differently.
	if(index==0)
	{
		new_node->next=head;
		head->prev=new_node;
		new_node->prev=NULL;
		*ptr2head=new_node;
	}
	else
	{
		// To reach till index, we have to traverse the list
		struct node* current_pointer=head;
		int count=0;
		while(count<index-1)
		{
			current_pointer=current_pointer->next;
			++count;
		}
		if(current_pointer->next==NULL)
		{
			current_pointer->next=new_node;
			new_node->prev=current_pointer;
			new_node->next=NULL;
		}
		else
		{
			new_node->next=current_pointer->next;
			current_pointer->next->prev=new_node;
			current_pointer->next=new_node;
			new_node->prev=current_pointer;
		}
	}
}

// Inputs
// reference to the head pointer
// The index at which we are deleting the nodes.
void delete_node(struct node** ptr2head, int index)
{
	struct node* head=*ptr2head;
	struct node* temp=head;
	if(index==0)
	{	
		*ptr2head=(*ptr2head)->next;
		head->prev=NULL;
		delete(temp);
	}
	else
	{	// To reach till the index, we have to traverse the list
		struct node* current_pointer=head;
		int count=0;
		while(count<index)
		{
			current_pointer=current_pointer->next;
			++count;
		}
		if(current_pointer->next==NULL)
		{
			temp=current_pointer;
			current_pointer->prev->next=NULL;
			delete(temp);
		}
		else
		{
			temp=current_pointer;
			current_pointer->prev->next=current_pointer->next;
			current_pointer->next->prev=current_pointer->prev;
			delete(temp);
		}
	}
}

int main()
{
	// Construct a linked list of 2 nodes to check the results.
	struct node* node_1 = new(struct node);
	struct node* node_2 = new(struct node);
	node_1->data=2;
	node_1->next=node_2;
	node_1->prev=NULL;
	node_2->data=3;
	node_2->prev=node_1;
	node_2->next=NULL;

	// Set the head node.
	struct node* head=node_1;

	// Add nodes at the required index.
	add_node(&head, 2, 1);



	// Print all the elements of the linked list.
	struct node* iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}
	cout<<"\n"<<endl;

	delete_node(&head, 2);
	// Print all the elements of the linked list.
	iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}
}