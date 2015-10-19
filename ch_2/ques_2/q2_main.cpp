#include <iostream>
#include <list>

int main()
{
	int my_array[]={41 , 63, 2, 78, 23, 98, 44, 56, 12, 87, 43, 17, 3, 77, 13, 96, 43};
	std::list<int> my_list(my_array, my_array+sizeof(my_array)/sizeof(int));

	int k = 5;
	std::list<int>::iterator fast_it=my_list.begin();
	std::list<int>::iterator slow_it=fast_it;
	
	for(int i=0; i<k; i++)
			++fast_it;

	while(fast_it!=my_list.end())
	{
		++fast_it;
		++slow_it;
	}

	std::cout<<*slow_it<<std::endl;
}