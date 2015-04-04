// test array based sparse matrix class

#include <iostream>
#include "sparseMatrix.h"

int main(void)
{
   sparseMatrix<int> a, b, c;

   // test input and output
   std::cin >> a;
   std::cout << "Matrix a is" << endl << a;
   std::cin >> b;
   std::cout << "Matrix b is" << endl << b;

   // test transpose
   a.transpose(c);
   std::cout << "The transpose of a is" << endl << c;

   // test add
   a.add(b,c);
   std::cout << "The sum of a and b is" << endl << c;

   return 0;
}
