// test matrix transpose

#include <iostream>
#include "matrixWithTranspose.h"

using namespace std;
int main(void)
{
   matrix<int> x(3,2), y, z;
   for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 2; j++)
         x(i,j) = 2*i + j;
   std::cout << "Initialized x(i,j) = 2*i + j" << endl;
   std::cout << "x is" << endl;;
   std::cout << x << endl;

    x.transpose(y);
   std::cout << "Assigned y = x.transpose" << endl;
   std::cout << "y is" << endl;
   std::cout << y << endl;

   return 0;
}
