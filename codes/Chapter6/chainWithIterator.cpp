// test the iterator for chain
#include<iostream>
#include<numeric>     // has accumulate
#include "linearList.h"
#include "chainWithIterator.h"

using namespace std;

int main()
{
   // create a chain
   chain<int> y;
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
   std::cout << "Size of y = " << y.size() << endl;

   // test iterator
   std::cout << "Ouput using forward iterators pre and post ++" << endl;
   for (chain<int>::iterator i = y.begin();
        i != y.end(); i++)
      std::cout << *i << "  ";
   std::cout << endl;
   for (chain<int>::iterator i = y.begin();
        i != y.end(); ++i)
   {
      std::cout << *i << "  ";
      *i += 1;
   }
   std::cout << endl;

   std::cout << "Incremented by 1 list is " << y << endl;
   
   // try out an STL algorithm
   int sum = accumulate(y.begin(), y.end(), 0);
   std::cout << "The sum of the elements is " << sum << endl;

   return 0;
}
