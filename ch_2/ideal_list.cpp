// I will be implementing Linked List from scratch but this time ideally :)
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

// Inputs
// 1. Pointer to the head
// 2. The index before which the node is to be added and
// 3. The data contained by the node.
void add_node(struct node** ptr2head, int index, int node_data)
{
	struct node* head=*ptr2head;
	// Create a node
	struct node* new_node = new(struct node);
	new_node->data=node_data;
	// Check if we need to add the node in the beginning
	if(index==0)
	{
		new_node->next=head;
		*ptr2head=new_node;
	}	
	else // For all other type of node addition
	{
		int count=0;
		struct node* previous_pointer;
		struct node* current_pointer=head;
		while(count<index)
		{
			previous_pointer=current_pointer;
			current_pointer=current_pointer->next;
			++count;
		}
		previous_pointer->next = new_node;
		new_node->next = current_pointer;
	}
}

// Inputs
// 1. Pointer to the head.
// 2. The index of the node that is to be deleted
void delete_node(struct node** ptr2head, int index)
{
	struct node* head=*ptr2head;
	struct node* temp;
	// Check if the node deletion is at the beginning or not?
	if(index==0)
	{
		// If the node that is to be deleted is at the beginning then we have to use the double pointer operation.
		temp=head;
		*ptr2head=(*ptr2head)->next;
		delete(temp);
	}
	else // For deletion at other indexes
	{
		int count=0;
		struct node* previous_pointer;
		struct node* current_pointer=head;
		while(count<index)
		{
			previous_pointer=current_pointer;
			current_pointer=current_pointer->next;
			++count;
		}
		temp=current_pointer;
		previous_pointer->next=current_pointer->next;
		delete(temp);
	}
}

int main()
{
	// Construct a linked list of 2 nodes to check the results.
	struct node* node_1 = new(struct node);
	struct node* node_2 = new(struct node);
	node_1->data=2;
	node_1->next=node_2;
	node_2->data=3;
	node_2->next=NULL;

	// Set the head node.
	struct node* head=node_1;

	// Add nodes
	add_node(&head, 2, 81);
	add_node(&head, 2, 82);
	add_node(&head, 2, 83);

	// Print all the elements of the linked list.
	struct node* iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}

	cout<<"\n"<<endl;

	// Remove nodes
	delete_node(&head, 2);
	delete_node(&head, 2);
	delete_node(&head, 2);

	// Print all the elements of the linked list.
	iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}
}