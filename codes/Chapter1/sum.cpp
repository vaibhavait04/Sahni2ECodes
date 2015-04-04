
// sum n numbers
#include<iostream>
#include<algorithm> // has copy
#include <iterator> 
using namespace std;

template<class T>
T sum(T a[], int n)
{// Return sum of the numbers a[0:n-1].
   T theSum = 0;
   for (int i = 0; i < n; i++)
      theSum += a[i];
   return theSum;
}

int main()
{
   int a[6] = {1, 2, 3, 4, 5, 6};

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, std::ostream_iterator<int>(cout, " "));
   std::cout << endl;

   // test the function sum
   std::cout << "sum(a,0) = " << sum(a,0) << endl;
   std::cout << "sum(a,1) = " << sum(a,1) << endl;
   std::cout << "sum(a,6) = " << sum(a,6) << endl;
   return 0;
}
