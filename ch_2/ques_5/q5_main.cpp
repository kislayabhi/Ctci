#include <iostream>
#include "../ideal_list.h"

using namespace std;

int main()
{
	struct node* node_1 = new(struct node);
	node_1->data=1;
	node_1->next=NULL;
	struct node* head_1=node_1;
	int i;
	for(i=1; i<9; ++i)
		add_node(&head_1, i, 1+i);

	struct node* node_2 = new(struct node);
	struct node* head_2=node_2;
	node_2->data=9;
	node_2->next=NULL;
	for(i=1; i<9; ++i)
		add_node(&head_2, i, 9);
	
	// The new linked list that we intend to create.
	struct node* node_new = new(struct node);
	node_new->next=NULL;
	node_new->data=0;
	struct node* head_new=node_new;

	// Now we have to write the iterative algorithm.
	int sum=0;
	// This one runs through the 1st linked list
	struct node* current_pointer_1=head_1;
	struct node* previous_pointer_1;
	// This one runs through the 2nd linked list
	struct node* current_pointer_2=head_2;
	struct node* previous_pointer_2;

	int count = -1;
	while(current_pointer_1!=NULL && current_pointer_2!=NULL)
	{	
		count++;
		
		previous_pointer_1=current_pointer_1;
		previous_pointer_2=current_pointer_2;

		current_pointer_1=current_pointer_1->next;
		current_pointer_2=current_pointer_2->next;



		sum = sum + previous_pointer_1->data + previous_pointer_2->data;
		//cout<<sum<<" "<<count<<endl;
		if (sum <= 9)
		 {
		 	// Push sum at the end of a new linked list.
		 	add_node(&head_new, count, sum);
		 	sum=0;
		 } 
		 else
		 {
		 	// push (x-10)
		 	//cout<<sum-10<<endl;
		 	add_node(&head_new, count, sum-10);
		 	sum=1;
		 }
	}

	// If sum is not zero, we have to add that sum as one more element at count+1.
	if (sum!=0)
		add_node(&head_new, count+1, sum);

	// Print the 1st linked list
	current_pointer_1 = head_1;
	while(current_pointer_1!=NULL)
	{
		cout<<current_pointer_1->data<<endl;
		current_pointer_1=current_pointer_1->next;
	}
	cout<<" "<<endl;

	// Print the 2nd linked list
	current_pointer_2 = head_2;
	while(current_pointer_2!=NULL)
	{
		cout<<current_pointer_2->data<<endl;
		current_pointer_2=current_pointer_2->next;
	}
	cout<<" "<<endl;

	//Print the new linkedlist
	struct node* current_pointer_3 = head_new;
	struct node* previous_pointer_3;
	while(current_pointer_3!=NULL)
	{
		previous_pointer_3=current_pointer_3;
		current_pointer_3=current_pointer_3->next;
		cout<<previous_pointer_3->data<<endl;
	}
}