// recursive sum of n numbers

#include <iostream>
#include <algorithm> // has copy
#include <iterator> 

using namespace std;

template<class T>
T rSum(T a[], int n)
{// Return sum of numbers a[0:n - 1].
   if (n > 0)
      return rSum(a, n-1) + a[n-1];
   return 0;
}
int main(void)
{
   int a[6] = {1, 2, 3, 4, 5, 6};

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(cout, " "));
   std::cout << endl;

   // test the function rSum
   std::cout << "rSum(a,0) = " << rSum(a,0) << endl;
   std::cout << "rSum(a,1) = " << rSum(a,1) << endl;
   std::cout << "rSum(a,6) = " << rSum(a,6) << endl;
   return 0;
}
