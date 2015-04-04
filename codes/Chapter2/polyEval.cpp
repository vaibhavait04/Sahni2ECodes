// evaluate a polynomial

#include <iostream>
#include <algorithm> // has copy
#include <iterator> 

using namespace std;


template<class T>
T polyEval(T coeff[], int n, const T& x)
{// Evaluate the degree n polynomial with
 // coefficients coeff[0:n] at the point x.
   T y = 1, value = coeff[0];
   for (int i = 1; i <= n; i++)
   {// add in next term
      y *= x;
      value += y * coeff[i];
   }
   return value;
}

int main()
{
   int a[6] = {1, 2, 3, 4, 5, 6};

   // output the coefficients
   std::cout << "The coefficients a[0:5] are ";
   copy(a, a+6, ostream_iterator<int>(cout, " "));
   std::cout << endl;

   std::cout << "The value at 2 is " << polyEval(a,5,2) << endl;
   std::cout << "The value at 1 is " << polyEval(a,5,1) << endl;
   std::cout << "The value at 0 is " << polyEval(a,5,0) << endl;
   return 0;
}
