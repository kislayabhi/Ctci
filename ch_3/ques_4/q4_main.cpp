#include <iostream>
#include <stack>
using namespace std;

void move(int count, stack<int>& from_stack, stack<int>& to_stack, stack<int>& aux_stack)
{

	// If count reaches two, then this is a base case.
	// You have to analytically put the data from the initial to the final stack.
	if(count==2)
	{
		cout<<"count 1 reached"<<endl;
		// Put top from "from_stack" to "aux_stack"
		// from_stack.pop() 
		// Put top from "from_stack" to "to_stack"
		// from_stack.pop() 
		// Put top from "aux_stack" to "to_stack"

		aux_stack.push(from_stack.top());
		from_stack.pop();
		to_stack.push(from_stack.top());
		from_stack.pop();
		to_stack.push(aux_stack.top());
		aux_stack.pop();
	}

	/*if(count<=0)
		return;*/

	else
	{
		cout<<"count: "<<count<<endl;
		// Move top n-1 members from "from_stack" to "aux_stack".
		move(count-1, from_stack, aux_stack, to_stack);
		
		cout<<"single hop"<<endl;
		// Move last element(nth) to "to_stack".
		to_stack.push(from_stack.top());
		from_stack.pop();

		// Move all members of "aux_stack" to "to_stack".
		move(count-1, aux_stack, to_stack, from_stack);
	}
}

int main()
{
	stack<int> first;
	stack<int> second;
	stack<int> third;

	for(int i=0; i<4; ++i)
	{
		first.push(4-i);
	}

	// We have count number of disks on the tower.
	int count=4;
	move(count, first, third, second);


	while(!third.empty())
	{
		cout<<third.top()<<endl;
		third.pop();
	}
}