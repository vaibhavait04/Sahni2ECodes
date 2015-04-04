// step count for sum of n numbers

#include <iostream>
#include <algorithm> // has copy
#include <iterator> 

using namespace std;

int stepCount = 0;

template<class T>
T sum(T a[], int n)
{// Return sum of numbers a[0:n - 1].
   T theSum = 0;
   stepCount++;    // for theSum = 0
   for (int i = 0; i < n; i++)
   {
      stepCount++; // for the for statement
      theSum += a[i];
      stepCount++; // for assignment
   }
   stepCount++;   // for last execution of for statement
   stepCount++;   // for return
   return theSum;
}

int main()
{
   int a[6] = {1, 2, 3, 4, 5, 6};

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(cout, " "));
   std::cout << endl;

   // determine the step count
   sum(a,0);
   std::cout << "For sum(a,0) the step count is " << stepCount << endl;
   stepCount = 0;
   sum(a,1);
   std::cout << "For sum(a,1) the step count is " << stepCount << endl;
   stepCount = 0;
   sum(a,6);
   std::cout << "For sum(a,6) the step count is " << stepCount << endl;
   return 0;
}
