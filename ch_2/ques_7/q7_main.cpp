#include <iostream>
#include <list>
#include <stack>
#include "../ideal_list.h"

using namespace std;

int main()
{
	struct node* node1 = new(struct node);
	node1->data=1;
	node1->next=NULL;

	struct node* head=node1;
	
	// Generate an odd numbered linked list
	int i;
	for(i=1; i<9; ++i)
		add_node(&head, i, 1+i);

	for(int k=i; k<17; ++k)
		add_node(&head, k, 2*i-k-1);		

	// Traverse the list.
	struct node* curr_ptr;
	curr_ptr=head;
	while(curr_ptr!=NULL)
	{
		cout<<curr_ptr->data<<endl;
		curr_ptr=curr_ptr->next;
	}

	cout<<"\n"<<endl;

	// We have the list ready.
	// Now find the middle of the list.
	struct node* f_ptr, *s_ptr;
	f_ptr=head;
	s_ptr=head;

	while((f_ptr->next)!=NULL && (f_ptr->next)->next!=NULL)
	{
		f_ptr=(f_ptr->next)->next;
		s_ptr=s_ptr->next;
	}
	
	// After the end of the loop, s_ptr is at the middle.
	// Traverse s_ptr to the end and put everything in stack.
	stack<int> reverse_data;
	while(s_ptr!=NULL)
	{
		// Push data.
		reverse_data.push(s_ptr->data);
		
		// Update s_ptr
		s_ptr=s_ptr->next;
	}

	// Moving the s_ptr from head again.
	s_ptr=head;
	while(!reverse_data.empty())
	{
		if(reverse_data.top()==s_ptr->data)
		{
			s_ptr=s_ptr->next;
			reverse_data.pop();
		}
		else
		{
			cout<<"Not a palindrome"<<endl;
			break;
		}
	}
}