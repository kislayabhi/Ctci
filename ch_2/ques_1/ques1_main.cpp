#include <iostream>
#include <list>
#include <map>

int main()
{
    
    // Don't initialize your list this way. Doing it this way makes it
    // non-changeable.
    int my_array[]={5, 9, 6, 5, 9};
    std::list<int> my_list(my_array, my_array+sizeof(my_array)/sizeof(int));
    

    /*std::list<int> my_list;
    my_list.push_back(5);
    my_list.push_back(9);
    my_list.push_back(6);
    my_list.push_back(5);
    my_list.push_back(9);
    my_list.push_back(6);*/


    /*
    Create a map
    We can use
    [1] list::erase . It is used to remove elements by their iterator.
    [2] list::remove is also useful. It removes all the elements whose value equals
    the one which is provided
    */

   std::map<int,bool> key_dict;

   for(std::list<int>::iterator it=my_list.begin(); it!=my_list.end(); ++it)
   {  

       if(key_dict.find(*it)==key_dict.end())
       // not found
          {
           // Don't confuse between square brackets and curved brackets.
           key_dict[*it]=true;
          }
       else
       // found
          {
            //std::cout<<*it<<std::endl;
            it=my_list.erase(it);
            it--;
          }
   }
   for(std::list<int>::iterator it=my_list.begin(); it!=my_list.end(); ++it)
   {
        std::cout<<*it<<std::endl;
   }

}
