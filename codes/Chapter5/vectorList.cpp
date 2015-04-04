// test the class vectorList that uses a vector for the list elements
#include<iostream>
#include<numeric>
#include<algorithm>   // has reverse
#include<functional>  // has greater
#include "linearList.h"
#include "vectorList.h"

using namespace std;

int main()
{
   // test constructor
   linearList<double> *x = new vectorList<double>(20);
   vectorList<int> y(2), z;

   // test capacity
   std::cout << "Capacity of x, y and z = "
        << ((vectorList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << endl;


   // test size
   std::cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << endl;

   // test empty
   if (x->empty()) std::cout << "x is empty" << endl;
   else std::cout << "x is not empty" << endl;
   if (y.empty()) std::cout << "y is empty" << endl;
   else std::cout << "y is not empty" << endl;

   // test insert
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
   std::cout << "Size of y = " << y.size() << endl;
   std::cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) std::cout << "y is empty" << endl;
   else std::cout << "y is not empty" << endl;
   y.output(cout);
   std::cout << endl << "Testing overloaded <<" << endl;
   std::cout << y << endl;

   // test indexOf
   int index = y.indexOf(4);
   if (index < 0) std::cout << "4 not found" << endl;
   else std::cout << "The index of 4 is " << index << endl;

   index = y.indexOf(7);
   if (index < 0) std::cout << "7 not found" << endl;
   else std::cout << "The index of 7 is " << index << endl;

   // test get
   std::cout << "Element with index 0 is " << y.get(0) << endl;
   std::cout << "Element with index 3 is " << y.get(3) << endl;

   // test erase
   y.erase(1);
   std::cout << "Element 1 erased" << endl;
   std::cout << "The list is "  << y << endl;
   y.erase(2);
   std::cout << "Element 2 erased" << endl;
   std::cout << "The list is "  << y << endl;

   std::cout << "Size of y = " << y.size() << endl;
   std::cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) std::cout << "y is empty" << endl;
   else std::cout << "y is not empty" << endl;

   try {y.insert(-3, 0);}
   catch (illegalIndex e)
   {
      std::cout << "Illegal index exception" << endl;
      std::cout << "Insert index must be between 0 and list size" << endl;
      e.outputMessage();
   }

   // test copy constructor
   vectorList<int> w(y);
   y.erase(0);
   y.erase(0);
   std::cout << "w should be old y, new y has first 2 elements removed" << endl;
   std::cout << "w is " << w << endl;
   std::cout << "y is " << y << endl;
   
   // a few more inserts, just for fun
   y.insert(0,4);
   y.insert(0,5);
   y.insert(0,6);
   y.insert(0,7);
   std::cout << "y is " << y << endl;

   // test iterator
   std::cout << "Ouput using forward iterators pre and post ++" << endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); i++)
      std::cout << *i << "  ";
   std::cout << endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); ++i)
      std::cout << *i << "  ";
   std::cout << endl;

   std::cout << "Ouput using backward iterators pre and post --" << endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin(); std::cout << *(--i) << "  ");
   std::cout << endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin();)
      {i--; std::cout << *i << "  "; *i += 1;} 
   std::cout << endl;
   std::cout << "Incremented by 1 list is " << y << endl;
   
   // try out some STL algorithms
   reverse(y.begin(), y.end());
   std::cout << "The reversed list is " << y << endl;
   int sum = accumulate(y.begin(), y.end(), 0);
   std::cout << "The sum of the elements is " << sum << endl;
   sort(y.begin(), y.end());
   std::cout << "The sorted list is " << y << endl;
   sort(y.begin(), y.end(), greater<int>());
   std::cout << "The list is descending order is " << y << endl;
   return 0;
}

