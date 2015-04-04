// test linked sparse matrix class

#include <iostream>
#include "linkedMatrix.h"

using namespace std;

int main(void)
{
   linkedMatrix<int> a, b, c;

   // test input and output
   std::cin >> a;
   std::cout << "Matrix a is" << endl << a;
   std::cin >> b;
   std::cout << "Matrix b is" << endl << b;

   // test transpose
   a.transpose(c);
   std::cout << "The transpose of a is" << endl << c;

   return 0;
}
