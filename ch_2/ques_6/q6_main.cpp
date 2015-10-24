#include <iostream>
#include <list>

using namespace std;

// I may have to first create a corrupted list.
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

int main()
{
	struct node* node_1 = new(struct node);
	struct node* node_2 = new(struct node);
	node_1->data=10;
	node_2->data=20;
	node_1->next=node_2;
	node_2->next=NULL;

	// Set the head node!
	struct node* head=node_1;

	add_node(&head, 2, 81);
	add_node(&head, 2, 79);
	add_node(&head, 2, 78);
	add_node(&head, 2, 77);
	add_node(&head, 2, 76);
	add_node(&head, 2, 75);
	add_node(&head, 2, 74);
	add_node(&head, 2, 73);
	add_node(&head, 2, 72);
	add_node(&head, 2, 71);

	struct node* current_pointer, *previous_pointer;
	current_pointer=head;
	
	cout<<current_pointer->data<<endl;

	// save the 4th pointer.
	struct node* node_4_pointer = (head->next)->next;

	while(current_pointer->next != NULL)
	{
		previous_pointer=current_pointer;
		current_pointer=current_pointer->next;
		cout<<current_pointer->data<<endl;
	}
	current_pointer->next=node_4_pointer;

	// Take a fast and slow running pointer on the linked list.
	// See where they meet!
	struct node* fast_runner, *slow_runner;

	// Initialize both the runners together.
	fast_runner=head;
	slow_runner=head;

	cout<<"\n"<<endl;

	cout<<slow_runner->data<<endl;

	
	while(true)
	{
		fast_runner = (fast_runner->next)->next;
		slow_runner = (slow_runner->next);
		cout<<slow_runner->data<<endl;
		if(fast_runner==slow_runner)
			break;
		//cout<<fast_runner->data<<endl;
	}
	// Slow runner is right now k steps behind the starting point
	// of the loop.

	// Now one of the runner will start from head. But both will
	// move one node at a time.
	fast_runner=head;
	while(true)
	{
		fast_runner=(fast_runner->next);
		slow_runner=(slow_runner->next);
		if (fast_runner==slow_runner)
		{
			cout<<"The result is: \n"<<endl;
			cout<<slow_runner->data<<endl;
			break;
		}
	}	
}