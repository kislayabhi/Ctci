#include <iostream>
#include <list>

// Global visited array
bool visited[]={0, 0, 0, 0};

// Dfs needs just the root of the graph.
void Dfs(int root, std::list<int>* adj)
{
	// int i=0;
	// while(i<4)
	// {
	// 	if(*((adj+i)->begin())==i)
	// 		break;
	// 	++i;
	// }

	// current list is adj+i
	std::list<int>::iterator h_p, c_p;
	h_p = (adj+root)->begin();
	c_p = h_p;
	visited[*h_p]=1;

	//while
	while(visited[*c_p]==1 && c_p!=(adj+root)->end())
	{
		++c_p;
	}

	if(c_p==(adj+root)->end())
		return;
	else
		{
			std::cout<<" -- "<<*c_p<<std::endl;
			Dfs(*c_p, adj);
		}

}

int main()
{
	// Create the following graph.
	//       0
	//      / \
	//     1   2
	//    /
	//   3

	// Make an array of Linked_list. Each contains the head node.
	std::list<int>* adj= new std::list<int>[4];
	adj->push_back(0);
	adj->push_back(1);
	adj->push_back(2);

	(adj+1)->push_back(1);
	(adj+1)->push_back(0);
	(adj+1)->push_back(3);

	(adj+2)->push_back(2);
	(adj+2)->push_back(0);

	(adj+3)->push_back(3);
	(adj+3)->push_back(1);

/*	
for(int i=0; i<4; ++i)
{
	for(std::list<int>::iterator it=(adj+i)->begin(); it!=(adj+i)->end(); ++it)
	{
		std::cout<<*it<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
}
*/
	Dfs(0, adj);

	for(int i=0; i<4; i++)
	{
		std::cout<<visited[i]<<std::endl;
	}
}
