#include <iostream>
#include <list>
#include <algorithm>

// This code is only compatible with C++ 11.

// Global visited array
bool visited[5]={0, 0, 0, 0, 0};

// Dfs needs just the root of the graph.
void Dfs(int root, std::list<int>* adj)
{	
	std::list<int>::iterator h_p, c_p;
	h_p = (adj+root)->begin();
	while( std::any_of(std::begin(visited), std::end(visited), [](bool i){return i==0;}) )
	{
    	c_p = h_p;
    	visited[*h_p]=1;
    
    	while(c_p!=(adj+root)->end() && visited[*c_p]==1)
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
    
    
        /*
        std::cout<<"--------------------"<<std::endl;
    	for(int i=0; i<5; i++)
    	{
    		std::cout<<visited[i] << " ";
    	}
    	std::cout<<" "<<std::endl;
    	std::cout<<"--------------------"<<std::endl;
    	*/
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
	std::list<int>* adj= new std::list<int>[5];
	
	// This doesn't work for graphs yet. only for trees.
	adj->push_back(0);
	adj->push_back(1);
	//adj->push_back(2);

	(adj+1)->push_back(1);
	(adj+1)->push_back(4);
	//(adj+1)->push_back(0);
	(adj+1)->push_back(3);
	//(adj+1)->push_back(2);

	(adj+2)->push_back(2);
	//(adj+2)->push_back(0);
	(adj+2)->push_back(4);
	//(adj+2)->push_back(3);

	(adj+3)->push_back(3);
	(adj+3)->push_back(1);
	(adj+3)->push_back(4);

    (adj+4)->push_back(4);
    (adj+4)->push_back(2);
    (adj+4)->push_back(3);
    (adj+4)->push_back(1);

	Dfs(0, adj);

	for(int i=0; i<4; i++)
	{
		std::cout<<visited[i]<<std::endl;
	}

}
