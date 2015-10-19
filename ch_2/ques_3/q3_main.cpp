/*
Implement an algorithm to delete a node in the middle of a singly linked list
given only acess to that node.
*/

// This can be done directly via list.erase() 
#include <iostream>
#include <list>

int main()
{
	int my_array[]={1,2,3,4,5};
	std::list<int> my_list(my_array, my_array+sizeof(my_array)/sizeof(int));
	std::list<int>::iterator iter=my_list.begin();
	
	// ++ operator basically does what ->next does in your data-structure
	for(int i=0; i<2; i++)
		iter++;
	// Now iter points to 3
	std::cout<<*iter<<std::endl;

	/*To delete this, we have to swap it with the next element.
	I had noted earler also that swapping is mostly feasible in LL 
	when the nodes are nearby.*/

	/*Swap data between the current node and the next node.*/
	std::list<int>::iterator next_node=iter;
	++next_node;

	int temp=*iter;
	*iter=*next_node;
	*next_node=temp;

	my_list.erase(next_node);

	for(std::list<int>::iterator it=my_list.begin(); it!=my_list.end(); ++it)
   	{
        std::cout<<*it<<std::endl;
   	}	
}

