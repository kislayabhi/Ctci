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

//Deleting a node from the linked list.
void delete_node_start(struct node** bighead)
{
	*bighead = *bighead->next;
}


// Inputs
// The pointer of the head of the linked list to which the new node is to be added.
// We need pointer to the node that is to be added.
// We also need a position where we want to add a node. THis can break into 2 parts
// namely, adding a node in the starting of the given linked list and 
// adding a node in the middle of the linked list maybe.
void add_node_start(struct node** daddy_head, struct node* new_pointer)
{
	// So my basic doubt is that when we are adding a node in the starting, how to
	// update the head pointer here. 
	// The answer is that here we need a double pointer to the head or else we 
	// won't be able to change the actual head variable. (We need a pointer to the
	// head pointer)
	new_pointer->next=*daddy_head;

	*daddy_head=new_pointer;
	// For some reason I am not able to print the following lines
	// cout<<*daddy_head->data<<endl;
}

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


// Adding nodes in between the linked lists.
// What are the additional inputs that I would need?
// The index 'after' which I want to add a node
void add_node_middle(struct node* head, struct node* new_pointer, int index)
{
	// First we have to traverse the Linked List until the position is exhausted.
	// This will give us the given index's element of the list in the current pointer.
	// We just need to append our new pointer here.
	struct node* current_pointer=head;
	struct node* previous_pointer;
	int count=0;
	while(count<=index)
	{
		previous_pointer=current_pointer;
		current_pointer=current_pointer->next;
		++count;
	}
	// Make the new element next pointer point to the next index's element
	new_pointer->next=previous_pointer->next;
	// Make the current pointer next point to the new pointer.
	previous_pointer->next=new_pointer;
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
	struct node fourth_node;
	struct node fifth_node;
	struct node sixth_node;
	
	second_node.data=98;
	third_node.data=97;

	fourth_node.data=45;
	fifth_node.data=46;

	sixth_node.data=57;

	add_node_end(head, &second_node);
	add_node_end(head, &third_node);
	add_node_start(&head, &fifth_node);
	add_node_start(&head, &fourth_node);

	
	
	add_node_middle(head, &sixth_node, 4);
	delete_node_start(&head);



	struct node* iter = head;
	while(iter != NULL)
	{
		cout<<iter->data<<endl;
		iter=iter->next;
	}
	cout<<"\n"<<endl;
}