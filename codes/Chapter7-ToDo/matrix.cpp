// test matrix class

#include <iostream>
#include "matrix.h"

using namespace std;
int main(void)
{
   try
   {
      matrix<int> x(3,2), y, z;
      int i, j;
      for (i = 1; i <= 3; i++)
         for (j = 1; j <= 2; j++)
            x(i,j) = 2*i + j;
      std::cout << "Initialized x(i,j) = 2*i + j" << endl;
      std::cout << "x(3,1) = " << x(3,1) << endl;
      std::cout << "x is" << endl;;
      std::cout << x << endl;

      y = x;
      std::cout << "Assigned y = x" << endl;
      std::cout << "y is" << endl;
      std::cout << y << endl;

      x += 2;
      std::cout << "x incremented by 2 is" << endl;
      std::cout << x << endl;

      z = y + x;
      std::cout << "y + x is" << endl;
      std::cout << z << endl;

      std::cout << "-(y + x) is" << endl;
      std::cout << -z << endl;

      matrix<int> w(2,3);
      for (i = 1; i <= 2; i++)
         for (j = 1; j <= 3; j++)
            w(i,j) = i + j;
      std::cout << "Initialized w(i,j) = i + j" << endl;
      std::cout << "w is" << endl;
      std::cout << w << endl;

      z = y * w;
      std::cout << "y * w is" << endl;
      std::cout << z << endl;
   }
   catch (...) {
      cerr << "An exception has occurred" << endl;}

   return 0;
}
