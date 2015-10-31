#include <iostream>
using namespace std;

/*
Things to take care of:
1. Count. It starts from 0. If you set a maximum length then always a -1 will come.
	ans setting count to be 0 and max_length-1 at appropriate places too!
2. Boundary cases like: what will happen when pop() is called and stack is empty?
 											 push() is called when stack is full?
3. stack* my_stack = new stack; is valid.
4. Heap allocation main reason is that we can control the deallocation. System controlled
   variables die after the function ends.
*/

// the stack data-structure
struct stack
{
	int* top;
	struct stack* next;
	struct stack* prev;
};

class SetOfStacks
{

public:
	// Function declarations

	// 1. Constructor
	SetOfStacks(int);

	// 2. Push
	void push(int);

	// 3. Pop
	void pop();

	// 4. This gives us the global top of SetOfStacks
	int get_top();

private:
	// Maximum size of each stack
	int max_limit;

	// current_stack points to the active stack.
	stack* current_stack;
	
	// Stores the index of the top in the current_stack.
	// 0 <= count <= max_limit
	int count;

	// function to create stack.
	void create_stack();

	// function to delete the current active stack.
	void delete_stack();
};

// Constructor definition
SetOfStacks::SetOfStacks(int maximum_limit)
{
	// Right now, current_stack points to NULL
	current_stack = 0;

	// Initialize count
	count = -1;

	// Initialize max_limit
	max_limit = maximum_limit;
}

// Create a new stack
void SetOfStacks::create_stack()
{
	// If I don't initialize this stack dynamically, it will die
	// after the function ends. 
	stack* my_stack = new stack;
	my_stack->top = new int[max_limit];
	
	// Connect this stack with the previous
	my_stack->prev=current_stack;

	// Activate this stack
	current_stack = my_stack;

	// This should be our last stack
	my_stack->next = 0;
}

// Delete the current stack
void SetOfStacks::delete_stack()
{
	struct stack* temp = current_stack;
	
	// Update the current stack to the previous one
	current_stack = current_stack->prev;
	delete(temp);
}

// push definition
void SetOfStacks::push(int data)
{	
	if(count == max_limit-1 || count == -1)
		{
			create_stack();
			*(current_stack->top) = data;
			//I FORGOT THIS
			count = 0;	
		}
	else
	 	{
			*(current_stack->top + 1) = data;
			++(current_stack->top);
			++count;
		}
}

// pop definition
void SetOfStacks::pop()
{
	if(count == -1)
		cout<<"The stack is empty"<<endl;
	
	else if(count == 0)
		// deleting a stack inherently deletes the last node.
		{
			delete_stack();	
			if(current_stack==0)
				count = -1;
			else
				count = max_limit-1;
		}
	else
		{
			--(current_stack->top);
			--count;
		}
}

// get_top definition
int SetOfStacks::get_top()
{
	if(current_stack==0)
		return -100;
	else
		return *(current_stack->top);
}

int main()
{
	SetOfStacks plates(4);
	plates.push(1);
	cout<<plates.get_top()<<endl;
	plates.push(2);
	cout<<plates.get_top()<<endl;
	plates.push(3);
	cout<<plates.get_top()<<endl;
	plates.push(4);
	cout<<plates.get_top()<<endl;
	plates.push(5);
	cout<<plates.get_top()<<endl;
	plates.push(6);
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	plates.pop();
	cout<<plates.get_top()<<endl;
	
}