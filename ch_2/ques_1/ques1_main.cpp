#include <iostream>
#include <list>
#include <map>

int main()
{
    
    int my_array[]={5, 9, 6, 5, 9};
    std::list<int> my_list(my_array, my_array+sizeof(my_array)/sizeof(int));
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
            // It is important to note here that we have to catch the return
            // iterator since the given one is invalidated for that node is 
            // no more.
            it=my_list.erase(it);
            // That iterator has to be decremented by 1.
            it--;
          }
   }
   for(std::list<int>::iterator it=my_list.begin(); it!=my_list.end(); ++it)
   {
        std::cout<<*it<<std::endl;
   }

}
