#include <iostream>
using namespace std;

struct node
{
	int data;
	int min;
	struct node* next;
};

class Stack
{
	public:
		// Default Constructor
		Stack();
		void push(int);
		void pop();
		struct node* get_top();
		int get_min();

	private:
		struct node* top;
		int global_minima;

};

// Default constructor
Stack::Stack()
{
	top = 0;
	global_minima=1000;
}

// Push operation
void Stack::push(int data)
{
	struct node* new_ptr = new(struct node);
	new_ptr->data = data;
	new_ptr->next = top;
	top = new_ptr;

	if(data<global_minima)
		{
			top->min=data;
			global_minima=data;
		}
	else
		top->min=global_minima;	
}

// Pop operation
void Stack::pop()
{
	// There is a memory leak here!
	struct node* temp = top;
	top=top->next;
	delete temp;
}

// get top
struct node* Stack::get_top()
{
	return top;
}

// get minima
int Stack::get_min()
{
	return get_top()->min;
}

int main()
{
	Stack mystack;
	mystack.push(6);
	cout<<mystack.get_min()<<endl;
	mystack.push(2);
	mystack.pop();
	cout<<mystack.get_min()<<endl;
	mystack.push(3);
	cout<<mystack.get_min()<<endl;
}