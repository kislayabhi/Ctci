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

   /* Now to do the same thing without using buffers */
   std::list<int> my_list2(my_array, my_array+sizeof(my_array)/sizeof(int));

   for(std::list<int>::iterator it1=my_list2.begin(); it1!=my_list2.end(); ++it1)
   {
      // Remember: You cannot do the following.
      // std::list<int>::iterator it2=it1+1;
      // This is so, since ++ is overloaded for the linear traversal(just like .next)
      std::list<int>::iterator it2=it1;
      it2++;
      for(it2; it2!=my_list2.end(); ++it2)
        if(*it1 == *it2)
        {
            it2=my_list2.erase(it2);
            it2--;
        }
   }

   for(std::list<int>::iterator it=my_list2.begin(); it!=my_list2.end(); ++it)
   {
        std::cout<<*it<<std::endl;
   }

}
