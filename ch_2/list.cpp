// Implement a Linked List from scratch.

// What are the operations that a linked list can perform
// 1. Insertion
// 2. Deletion

#include <iostream>
using namespace std;

// Implemention of a node for a Linked List.
struct node
{
	int data;
	struct node* next;
};

// Inputs
// The pointer of the head of the linked list to which the new node is to be added.
// We need pointer to the node that is to be added.
// We also need a position where we want to add a node. THis can break into 2 parts
// namely, adding a node in the starting of the given linked list and 
// adding a node in the middle of the linked list maybe.
void add_node_end( struct node* head, struct node* new_pointer)
{
	struct node* current_pointer=head;
	// We have to maintain this previous pointer thing since once a pointer is assigned
	// NULL, every linkage to its back is destroyed.(Thats what I think for now.)
	struct node* previous_pointer;
	
	// current_pointer = current_pointer->next;
	while(current_pointer != NULL)
	{
		previous_pointer = current_pointer;
		current_pointer = current_pointer->next;
	}
	previous_pointer->next=new_pointer;
	new_pointer->next=NULL;
}

int main()
{
	// Defining the first node explicitly for the linked list.
	struct node first_node;

	// Setting the parameters of the first node.
	first_node.data = 4;
	first_node.next = NULL;

	// Initializing a head pointer.
	struct node* head = &first_node;

	// Accessing the value of the data parameter by derefencing the pointers will give an error.
	// head is a pointer variable that points to the data-structure "struct node" which unlike an array 
	// doesn't point to something meaningful(There it implemented the base adress.)
	// cout<<*head<<endl;

	// Accessing the data from the pointer directly.
	//cout<<head->data<<endl;

	// Resetting the data of the first node using the head pointer.
	head->data = 19;

	// Accessing the data from the pointer directly.
	//cout<<head->data<<endl;

	// Accessing the pointer next in the first node. The compiler maintains the fact that at the address 0,
	// nothing is kept.
	//cout<<head->next<<endl;

	// Adding another node to the above linked list with the first element.
	// Writing "struct node* second_node, third_node;" is wrong.
	struct node second_node;
	struct node third_node;
	
	second_node.data=98;
	third_node.data=97;

	add_node_end(head, &second_node);
	add_node_end(head, &third_node);

	struct node* iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}
}