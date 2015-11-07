#include <iostream>
#include <queue>
#include <list>

bool visited[]={0,0,0,0,0,0,0,0};

// my root co-incides with the position of that vertex linked-list from the linked-list array
// that is, I can access root's linked list using *(adj+root) or adj[root]
void bfs( int root, std::list<int>* adj)
{
	std::queue<int> bfs_queue;
	int el;
	std::list<int>::iterator hp, cp;

	// we enque the root here.
	bfs_queue.push(root);
	// Every_push determines the reached or to be reached elements
	visited[root]=1;

	while(!bfs_queue.empty())
	{
		el=bfs_queue.front();
		std::cout<<"completed node: "<<el<<std::endl;
		bfs_queue.pop();

		// Enque all the level-1 children of el.
		hp=(adj+(el))->begin();
		cp=hp;
		while(cp!=(adj+(el))->end())
		{
			if(visited[*cp]==0)
			{
				bfs_queue.push(*cp);
				visited[*cp]=1;
			}
			cp++;
		}
	}
}

int main()
{
	// We need the adjacency list to store the graph.
	// Array of lists.
	std::list<int>* adj = new std::list<int>[8];

	// This doesn't work for graphs yet. only for trees.
	adj->push_back(0);
	adj->push_back(1);

	(adj+1)->push_back(1);
	(adj+1)->push_back(0);
	(adj+1)->push_back(2);
	(adj+1)->push_back(3);
	(adj+1)->push_back(7);

	(adj+2)->push_back(2);
	(adj+2)->push_back(4);
	(adj+2)->push_back(5);
	(adj+2)->push_back(1);

	(adj+3)->push_back(3);
	(adj+3)->push_back(5);
	(adj+3)->push_back(1);
	(adj+3)->push_back(6);

	(adj+4)->push_back(4);
	(adj+4)->push_back(2);

	(adj+5)->push_back(5);
	(adj+5)->push_back(2);
	(adj+5)->push_back(3);
	//(adj+5)->push_back(6);
	//(adj+5)->push_back(7);

	(adj+6)->push_back(6);
	(adj+6)->push_back(3);
	//(adj+6)->push_back(5);

	(adj+7)->push_back(7);
	(adj+7)->push_back(1);
	//(adj+7)->push_back(5);

	bfs(0, adj);
}