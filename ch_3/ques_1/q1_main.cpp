// Implementing a stack using an array.
#include <iostream>
using namespace std;

// A stack for containing integers
class My_stack
{
	// Size of the array, initialized by the constructor.
	int my_size;

	// Currently in use
	int c_use;

	// initialize an array.
	int* my_array;

	// Default is private
	// the pointer to the top variable.
	// Initially it should point to NULL.
	int* top;

	public:
		// The constructor!
		My_stack(int x)
		{
			my_size = x;
			c_use = 0;
			top = 0;
			my_array = new int [my_size];
		}

		// The function push
		void push(int data)
		{
			// The case where the stack is empty
			if(top == 0)
				top = my_array;
			// The case where the capacity is reached
			else if(c_use>=my_size)
			{
				cout<<"limit reached"<<endl;
				return;
			}
			else
				 top = top + 1;
			
			*top = data;
			c_use++;
		}

		// The function pop
		void pop()
		{
			// The case where stack is empty
			if(top == 0)
			{
				cout<<"Stack is empty"<<endl;
				return;
			}

			top = top - 1;
			c_use--;
		}

		// Get the pointer to the topmost element in the stack
		int* get_top()
		{
			return top;
		}
};


int main()
{
	My_stack kislay(5);
	kislay.push(1);
	cout<<*kislay.get_top()<<endl;
	kislay.push(2);
	cout<<*kislay.get_top()<<endl;
	kislay.push(3);

	cout<<*kislay.get_top()<<endl;
	
	kislay.push(6);
	cout<<*kislay.get_top()<<endl;
	kislay.push(9);
	cout<<*kislay.get_top()<<endl;

	kislay.push(12);
	kislay.push(17);

}