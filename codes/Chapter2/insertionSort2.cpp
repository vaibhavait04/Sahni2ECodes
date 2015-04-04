// test insertion sort

#include <iostream>
#include <algorithm> // has copy
#include "insertionSort.h"
#include <iterator> 

using namespace std;


int main()
{
   int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

   // output the elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   std::cout << endl;

   // sort
   insertionSort(a,10);

   // output the sorted sequence
   std::cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   std::cout << endl;
   return 0;
}
